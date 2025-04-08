import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'board_provider.dart';

Future<void> showEditTaskDialog(BuildContext context, Task task, String listId, int userId) async
{
  String? taskTitle = task.title;
  String? taskDescription = task.description;
  DateTime? taskDueDate = task.dueDate;

  showDialog(
    context: context,
    builder: (context) {
      return AlertDialog(
        title: const Text('Edit Task'),
        content: Column(
          mainAxisSize: MainAxisSize.min,
          children: [
            TextField(
              decoration: const InputDecoration(hintText: 'Task Title'),
              controller: TextEditingController(text: taskTitle),
              onChanged: (value) => taskTitle = value,
            ),
            TextField(
              decoration: const InputDecoration(hintText: 'Task Description'),
              controller: TextEditingController(text: taskDescription),
              onChanged: (value) => taskDescription = value,
            ),
            ElevatedButton(
              onPressed: () async {
                taskDueDate = await showDatePicker(
                  context: context,
                  initialDate: taskDueDate ?? DateTime.now(),
                  firstDate: DateTime.now(),
                  lastDate: DateTime(2100),
                );
              },
              child: Text(taskDueDate == null
                  ? 'Select Due Date'
                  : 'Due Date: ${taskDueDate.toString().substring(0, 10)}'),
            ),
          ],
        ),
        actions: [
          TextButton(
            onPressed: () => Navigator.of(context).pop(),
            child: const Text('Cancel'),
          ),
          TextButton(
            onPressed: () async {
              // Delete task
              await Provider.of<BoardProvider>(context, listen: false).deleteTask(task.id, userId);
              Navigator.of(context).pop();
            },
            child: const Text('Delete Task'),
          ),
          ElevatedButton(
            onPressed: () async {
              if (taskTitle?.isNotEmpty == true) {
                await Provider.of<BoardProvider>(context, listen: false)
                    .updateTask(task.id, taskTitle!, taskDescription ?? '', taskDueDate, listId, userId);
                Navigator.of(context).pop();
              }
            },
            child: const Text('Update Task'),
          ),
        ],
      );
    },
  );
}

Future<void> showAddTaskDialog(BuildContext context, String listId, int userId) async
{
  String? taskTitle;
  String? taskDescription;
  DateTime? taskDueDate;

  showDialog(
    context: context,
    builder: (context) {
      return AlertDialog(
        title: const Text('Add Task'),
        content: Column(
          mainAxisSize: MainAxisSize.min,
          children: [
            TextField(
              decoration: const InputDecoration(hintText: 'Task Title'),
              onChanged: (value) => taskTitle = value,
            ),
            TextField(
              decoration: const InputDecoration(hintText: 'Task Description'),
              onChanged: (value) => taskDescription = value,
            ),
            ElevatedButton(
              onPressed: () async {
                taskDueDate = await showDatePicker(
                  context: context,
                  initialDate: DateTime.now(),
                  firstDate: DateTime.now(),
                  lastDate: DateTime(2100),
                );
              },
              child: Text(taskDueDate == null
                  ? 'Select Due Date'
                  : 'Due Date: ${taskDueDate.toString().substring(0, 10)}'),
            ),
          ],
        ),
        actions: [
          TextButton(
            onPressed: () => Navigator.of(context).pop(),
            child: const Text('Cancel'),
          ),
          ElevatedButton(
            onPressed: () async {
              if (taskTitle?.isNotEmpty == true) {
                await Provider.of<BoardProvider>(context, listen: false)
                    .createTask(taskTitle!, taskDescription ?? '', taskDueDate, listId, userId);
                Navigator.of(context).pop();
              }
            },
            child: const Text('Add Task'),
          ),
        ],
      );
    },
  );
}

Future<void> moveTask(Task task, String targetListId, int userId, BoardProvider boardProvider) async
{
  try {
    await boardProvider.moveTask(task.id, task.listId, targetListId, userId);
  } catch (e) {
    debugPrint("Error moving task: $e");
  }
}
