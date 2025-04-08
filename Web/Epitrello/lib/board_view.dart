import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'board_provider.dart';
import 'menu.dart';
import 'user.dart';
import 'task_dialogs.dart';
import 'collaborator_dialogs.dart';
import 'package:url_launcher/url_launcher.dart';
import 'package:shared_preferences/shared_preferences.dart';
import 'dart:convert';
import 'package:http/http.dart' as http;

class BoardView extends StatelessWidget {
  final Board board;

  const BoardView({Key? key, required this.board}) : super(key: key);

  // Function to create a notification
  Future<void> createNotification(int userId, String type, int relatedId, String message) async {
    const url = 'http://localhost:3000/create-notification';

    final response = await http.post(
      Uri.parse(url),
      headers: {'Content-Type': 'application/json'},
      body: jsonEncode({
        'userId': userId,
        'type': type,
        'relatedId': relatedId,
        'message': message,
      }),
    );

    if (response.statusCode == 200) {
      final data = jsonDecode(response.body);
      if (data['success']) {
        print('Notification created successfully');
      } else {
        print('Failed to create notification');
      }
    } else {
      print('Error: ${response.statusCode}');
      print('Response body: ${response.body}');
    }
  }

//   // Function to exchange code for GitHub token
//   Future<void> exchangeCodeForToken(String code) async {
//     const clientId = 'Ov23li4rpBAJxNLbVf5D';
//     const clientSecret = 'd35d328242d2ee8b3c9dff1d19df26bdabf51caa';

//     final response = await http.post(
//       Uri.parse('https://github.com/login/oauth/access_token'),
//       headers: {'Accept': 'application/json'},
//       body: {
//         'client_id': clientId,
//         'client_secret': clientSecret,
//         'code': code,
//       },
//     );

//     if (response.statusCode == 200) {
//       final data = jsonDecode(response.body);
//       if (data['access_token'] != null) {
//         String token = data['access_token'];
//         print('GitHub Token: $token');
//         await saveGitHubToken(token);
//         print('GitHub Token saved successfully!');
//       } else {
//         print('Failed to get access token: ${data['error_description']}');
//       }
//     } else {
//       print('Error: ${response.statusCode}');
//     }
//   }

  // Function to create GitHub issue
  Future<void> createGitHubIssue(String taskTitle) async {
    // Replace with your function to fetch the token from the database
    final token = await getGitHubTokenFromDatabase();
    
    if (token == null) {
      print('GitHub token is missing. Please authenticate.');
      return;
    }

    final response = await http.post(
      Uri.parse('https://api.github.com/repos/tibaudlemaout/epitrellorepo/issues'),
      headers: {
        'Authorization': 'Bearer $token',
        'Accept': 'application/vnd.github.v3+json',
      },
      body: jsonEncode({
        'title': taskTitle,
        'body': 'This task was created in your Trello-like app.',
      }),
    );

    print('GitHub API Response Status: ${response.statusCode}');
    print('GitHub API Response Body: ${response.body}');

    if (response.statusCode == 201) {
      print('GitHub issue created successfully!');
    } else {
      print('Failed to create issue: ${response.body}');
    }
  }

Future<String?> getGitHubTokenFromDatabase() async {
    final url = 'http://localhost:3000/get-github-token'; // Endpoint to fetch the token

    final response = await http.get(Uri.parse(url));

    if (response.statusCode == 200) {
      final data = jsonDecode(response.body);
      if (data['token'] != null) {
        return data['token'];
      } else {
        print('No token found in database.');
        return null;
      }
    } else {
      print('Failed to retrieve token from database: ${response.statusCode}');
      return null;
    }
  }

  @override
  Widget build(BuildContext context) {
    final userId = Provider.of<UserProvider>(context).user?.userId;

    return Scaffold(
      body: Row(
        children: [
          const SideMenu(),
          Expanded(
            child: Padding(
              padding: const EdgeInsets.all(16.0),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  AppBar(
                    title: Text(board.title),
                    actions: [
                      IconButton(
                        icon: const Icon(Icons.group_add),
                        onPressed: () {
                          if (userId != null) {
                            showAddCollaboratorDialog(context, board.id, userId);
                          } else {
                            ScaffoldMessenger.of(context).showSnackBar(
                              const SnackBar(content: Text('User ID is required to add a collaborator.')),
                            );
                          }
                        },
                      ),
                      IconButton(
                        icon: const Icon(Icons.people),
                        onPressed: () {
                          showCollaboratorsList(context, board.id);
                        },
                      ),
                      ElevatedButton.icon(
                        onPressed: () async {
                          const githubUrl = "https://github.com/login/oauth/authorize"
                              "?client_id=Ov23li4rpBAJxNLbVf5D"
                              "&scope=repo issues";

                          final Uri uri = Uri.parse(githubUrl);
                          if (await canLaunchUrl(uri)) {
                            await launchUrl(uri, mode: LaunchMode.externalApplication);
                          } else {
                            print("Could not open GitHub login page.");
                          }
                        },
                        icon: const Icon(Icons.login),
                        label: const Text('Connect GitHub'),
                      ),
                    ],
                  ),
                  const SizedBox(height: 20),
                  const Text(
                    'Lists',
                    style: TextStyle(fontSize: 22, fontWeight: FontWeight.bold),
                  ),
                  const SizedBox(height: 20),
                  Expanded(
                    child: Consumer<BoardProvider>(
                      builder: (context, boardProvider, child) {
                        final updatedBoard = boardProvider.boards
                            .firstWhere((b) => b.id == board.id);

                        return ListView.builder(
                          scrollDirection: Axis.horizontal,
                          itemCount: updatedBoard.lists.length,
                          itemBuilder: (context, index) {
                            final list = updatedBoard.lists[index];

                            return Padding(
                              padding: const EdgeInsets.only(right: 16.0),
                              child: Container(
                                width: 300,
                                child: DragTarget<Task>(
                                  onAcceptWithDetails: (details) async {
                                    if (userId != null) {
                                      final task = details.data;
                                      await moveTask(task, list.id, userId, boardProvider);
                                    }
                                  },
                                  onWillAcceptWithDetails: (details) {
                                    final task = details.data;
                                    return task.listId != list.id;
                                  },
                                  builder: (context, candidateData, rejectedData) {
                                    return Container(
                                      width: 300,
                                      decoration: BoxDecoration(
                                        color: candidateData.isNotEmpty
                                            ? Colors.blue.shade200
                                            : Colors.blue.shade100,
                                        borderRadius: BorderRadius.circular(10),
                                      ),
                                      child: Padding(
                                        padding: const EdgeInsets.all(16.0),
                                        child: Column(
                                          crossAxisAlignment: CrossAxisAlignment.start,
                                          children: [
                                            Text(
                                              list.title,
                                              style: const TextStyle(
                                                  fontSize: 18,
                                                  fontWeight: FontWeight.bold),
                                            ),
                                            const SizedBox(height: 10),
                                            Expanded(
                                              child: list.tasks.isNotEmpty
                                                  ? ListView.builder(
                                                      itemCount: list.tasks.length,
                                                      itemBuilder: (context, taskIndex) {
                                                        final task = list.tasks[taskIndex];

                                                        return Draggable<Task>(
                                                          data: task,
                                                          feedback: Material(
                                                            color: Colors.transparent,
                                                            child: Container(
                                                              padding: const EdgeInsets.all(8.0),
                                                              width: 300,
                                                              child: Card(
                                                                elevation: 4,
                                                                child: ListTile(
                                                                  title: Text(task.title),
                                                                ),
                                                              ),
                                                            ),
                                                          ),
                                                          childWhenDragging: Opacity(
                                                            opacity: 0.5,
                                                            child: Card(
                                                              child: ListTile(
                                                                title: Text(task.title),
                                                              ),
                                                            ),
                                                          ),
                                                          child: Card(
                                                            child: ListTile(
                                                              title: Text(task.title),
                                                              subtitle: task.description?.isNotEmpty == true
                                                                  ? Text(task.description!)
                                                                  : null,
                                                              trailing: task.dueDate != null
                                                                  ? Text(
                                                                      'Due: ${task.dueDate}',
                                                                      style: const TextStyle(fontSize: 12),
                                                                    )
                                                                  : null,
                                                              onTap: () {
                                                                if (userId != null) {
                                                                  showEditTaskDialog(context, task, list.id, userId);
                                                                }
                                                              },
                                                            ),
                                                          ),
                                                        );
                                                      },
                                                    )
                                                  : const Center(
                                                      child: Text("No tasks in this list."),
                                                    ),
                                            ),
                                            const SizedBox(height: 10),
                                            ElevatedButton.icon(
                                              onPressed: () {
                                                if (userId != null) {
                                                  showAddTaskDialog(context, list.id, userId);
                                                  // Create notification for the new task
                                                  createNotification(userId, 'task_created', int.parse(list.id), 'New task added to list: ${list.title}');
                                                  createGitHubIssue(list.title);
                                                }
                                              },
                                              icon: const Icon(Icons.add),
                                              label: const Text('Add Task'),
                                            ),
                                          ],
                                        ),
                                      ),
                                    );
                                  },
                                ),
                              ),
                            );
                          },
                        );
                      },
                    ),
                  ),
                  const SizedBox(height: 20),
                  ElevatedButton.icon(
                    onPressed: () async {
                      if (userId != null) {
                        String? newListName = await showDialog<String>(
                          context: context,
                          builder: (context) {
                            return AlertDialog(
                              title: const Text('Create New List'),
                              content: TextField(
                                autofocus: true,
                                decoration: const InputDecoration(hintText: 'List Name'),
                                onSubmitted: (value) {
                                  Navigator.of(context).pop(value);
                                },
                              ),
                            );
                          },
                        );
                        if (newListName != null && newListName.isNotEmpty) {
                          Provider.of<BoardProvider>(context, listen: false)
                              .createList(board.id, newListName, userId);
                          // Create notification for the new list
                          createNotification(userId, 'list_created', int.parse(board.id), 'New list created: $newListName');
                        }
                      }
                    },
                    icon: const Icon(Icons.add),
                    label: const Text('Add List'),
                  ),
                ],
              ),
            ),
          ),
        ],
      ),
    );
  }

  // Show Collaborators List
  void showCollaboratorsList(BuildContext context, String boardId) {
    // Fetch the list of collaborators
    final collaborators = Provider.of<BoardProvider>(context, listen: false).getCollaborators(boardId);

    showDialog(
      context: context,
      builder: (context) {
        return AlertDialog(
          title: const Text('Collaborators'),
          content: Column(
            mainAxisSize: MainAxisSize.min,
            children: collaborators.map<Widget>((collaborator) {
              return ListTile(
                title: Text(collaborator),
                trailing: IconButton(
                  icon: const Icon(Icons.remove_circle_outline),
                  onPressed: () async {
                    await showRemoveCollaboratorDialog(context, boardId);
                    Navigator.pop(context);  // Close the dialog after removal
                  },
                ),
              );
            }).toList(),
          ),
        );
      },
    );
  }
}
