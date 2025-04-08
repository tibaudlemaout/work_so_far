import 'dart:convert';
import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;

class Task {
  final String id;
  final String listId;
  final String title;
  final String description;
  final DateTime? dueDate;
  final bool completed;

  Task({
    required this.id,
    required this.listId, // Include it in the constructor
    required this.title,
    this.description = '',
    this.dueDate,
    this.completed = false,
  });
}

class ListItem {
  final String id;
  final String title;
  final List<Task> tasks;

  ListItem({required this.id, required this.title, required this.tasks});
}

class Board {
  final String id;
  final String title;
  final List<ListItem> lists;
  List<String> collaborators; // List of collaborator emails

  Board({required this.id, required this.title, required this.lists, this.collaborators = const [],});
}

class BoardProvider with ChangeNotifier
{
  List<Board> boards = [];

  Future<List<Board>> fetchBoards(int userId) async
  {
    final response = await http.get(Uri.parse('http://localhost:3000/boards?user_id=$userId'));

    if (response.statusCode == 200) {
      final List<dynamic> data = json.decode(response.body);
      boards = data.map<Board>((boardData) {
        final List<ListItem> listItems = (boardData['lists'] as List).map<ListItem>((listData) {
          final List<Task> tasks = (listData['tasks'] as List?)?.map<Task>((taskData) {
            return Task(
              id: taskData['task_id'].toString(),
              listId: listData['list_id'].toString(),
              title: taskData['title'],
              description: taskData['description'] ?? '',
              dueDate: taskData['due_date'] != null
                  ? DateTime.parse(taskData['due_date'])
                  : null,
              completed: taskData['completed'] == 1,
            );
          }).toList() ?? [];  // Return empty list if no tasks
          return ListItem(
            id: listData['list_id'].toString(),
            title: listData['name'],
            tasks: tasks,
          );
        }).toList();
        return Board(
          id: boardData['board_id'].toString(),
          title: boardData['name'],
          lists: listItems,
        );
      }).toList();
      notifyListeners();
      return boards;
    } else {
      throw Exception('Failed to load boards');
    }
  }

  Future<void> createBoard(String title, int userId) async
  {
    final response = await http.post(Uri.parse('http://localhost:3000/boards'),
      headers: {'Content-Type': 'application/json'},
      body: json.encode({'name': title, 'user_id': userId}),
    );

    if (response.statusCode == 201) {
      await fetchBoards(userId);
    } else {
      throw Exception('Failed to create board');
    }
  }

  void createList(String boardId, String listName, int userId) async
  {
    final response = await http.post(
      Uri.parse('http://localhost:3000/lists'),
      body: json.encode({
        'board_id': boardId,
        'name': listName,
      }),
      headers: {
        'Content-Type': 'application/json',
      },
    );

    if (response.statusCode == 201) {
      // If the creation is successful, refresh the board's data
      await fetchBoards(userId);
    } else {
      throw Exception('Failed to create list');
    }
  }

  Future<void> createTask(String title, String description, DateTime? dueDate, String listId, int userId) async
  {
    final response = await http.post(
      Uri.parse('http://localhost:3000/tasks'),
      headers: {'Content-Type': 'application/json'},
      body: json.encode({
        'title': title,
        'description': description,
        'due_date': dueDate?.toIso8601String(),
        'list_id': listId,
      }),
    );

    if (response.statusCode == 201) {
      final createdTaskData = json.decode(response.body);
      final newTask = Task(
        id: createdTaskData['task_id'].toString(),
        listId: createdTaskData['list_id'].toString(),
        title: createdTaskData['title'],
        description: createdTaskData['description'] ?? '',
        dueDate: createdTaskData['due_date'] != null
            ? DateTime.parse(createdTaskData['due_date'])
            : null,
        completed: createdTaskData['completed'] == 1,
      );
      for (var board in boards) {
        for (var list in board.lists) {
          if (list.id == listId) {
            list.tasks.add(newTask);
            break;
          }
        }
      }
      notifyListeners();
    } else {
      throw Exception('Failed to create task');
    }
  }

  Future<void> updateTask(String taskId, String title, String description, DateTime? dueDate, String listId, int userId) async
  {
    final response = await http.put(
      Uri.parse('http://localhost:3000/tasks/$taskId'),
      headers: {
        'Content-Type': 'application/json',
      },
      body: jsonEncode({
        'title': title,
        'description': description,
        'due_date': dueDate?.toIso8601String(),
        'list_id': listId,
      }),
    );

    if (response.statusCode == 200) {
      await fetchBoards(userId); // Refresh the boards
    } else {
      throw Exception('Failed to update task');
    }
  }

  Future<void> deleteTask(String taskId, int userId) async
  {
    final response = await http.delete(Uri.parse('http://localhost:3000/tasks/$taskId'));

    print('Response status: ${response.statusCode}');
    print('Response body: ${response.body}');

    if (response.statusCode == 200) {
      await fetchBoards(userId);
    } else {
      throw Exception('Failed to delete task: ${response.body}');
    }
  }

  Future<void> moveTask(String taskId, String fromListId, String toListId, int userId) async {
    final response = await http.put(
      Uri.parse('http://localhost:3000/tasks/$taskId/move'),
      headers: {'Content-Type': 'application/json'},
      body: json.encode({
        'newListId': toListId,
        'newPosition': null,
      }),
    );

    if (response.statusCode == 200) {
      await fetchBoards(userId); // Refresh the boards
    } else {
      throw Exception('Failed to move task');
    }
  }
  

  // Get the list of collaborators for a board
  List<String> getCollaborators(String boardId)
  {
    try {
      final board = boards.firstWhere((b) => b.id == boardId);

      return board.collaborators;
    } catch (e) {
      debugPrint("Error fetching collaborators: $e");
      return [];
    }
  }

  Future<void> addCollaborator(String boardId, String collaboratorEmail) async
  {
    try {
      final userId = await _getUserIdByEmail(collaboratorEmail);
      if (userId == null) {
        throw Exception("Collaborator not found.");
      }

      final response = await http.post(
        Uri.parse('http://localhost:3000/boards/$boardId/collaborators'),
        headers: {'Content-Type': 'application/json'},
        body: json.encode({'userId': userId}),
      );

      print('Response Status: ${response.statusCode}');
      print('Response Body: ${response.body}');
      
      if (response.statusCode == 201) {
        // Success: Collaborator added
        notifyListeners();
      } else {
        throw Exception("Failed to add collaborator: ${response.body}");
      }
    } catch (e) {
      debugPrint("Error adding collaborator: $e");
      throw Exception("Failed to add collaborator.");
    }
  }

  Future<void> removeCollaborator(String boardId, String collaboratorEmail) async
  {
    try {
      final userId = await _getUserIdByEmail(collaboratorEmail);
      if (userId == null) {
        throw Exception("Collaborator not found.");
      }
      final response = await http.delete(
        Uri.parse('http://localhost:3000/boards/$boardId/collaborators/$userId'),
        headers: {'Content-Type': 'application/json'},
      );

      if (response.statusCode == 200) {
        // Success: Collaborator removed
        notifyListeners();
      } else {
        throw Exception("Failed to remove collaborator.");
      }
    } catch (e) {
      debugPrint("Error removing collaborator: $e");
      throw Exception("Failed to remove collaborator.");
    }
  }

  Future<int?> _getUserIdByEmail(String email) async
  {
    final response = await http.get(
      Uri.parse('http://localhost:3000/users/email/$email'),
    );

    if (response.statusCode == 200) {
      final data = json.decode(response.body);
      return data['user_id'];
    } else {
      return null; // User not found or error
    }
  }

  Future<void> createBoardFromTemplate({required String boardName, required int userId, required int templateId,}) async
  {
    final url = Uri.parse('http://localhost:3000/template-boards');
    
    final body = jsonEncode({
      'name': boardName,
      'user_id': userId,
      'template_id': templateId,
    });
    try {
      final response = await http.post(
        url,
        headers: {
          'Content-Type': 'application/json',
        },
        body: body,
      );

      if (response.statusCode == 201) {
        notifyListeners(); // Update UI
      } else {
        throw Exception('Failed to create board: ${response.body}');
      }
    } catch (e) {
      debugPrint('Error creating board: $e');
    }
  }
}

