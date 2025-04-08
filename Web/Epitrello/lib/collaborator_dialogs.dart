import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'board_provider.dart';

Future<void> showAddCollaboratorDialog(BuildContext context, String boardId, int userId) async
{
  String? collaboratorEmail = await showDialog<String>(
    context: context,
    builder: (context) {
      return AlertDialog(
        title: const Text('Add Collaborator'),
        content: TextField(
          decoration: const InputDecoration(hintText: 'Collaborator Email'),
          onSubmitted: (value) {
            Navigator.of(context).pop(value);
          },
        ),
      );
    },
  );

  if (collaboratorEmail != null && collaboratorEmail.isNotEmpty) {
    try {
      await Provider.of<BoardProvider>(context, listen: false)
          .addCollaborator(boardId, collaboratorEmail);
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('Collaborator added successfully!')),
      );
    } catch (e) {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text('Error adding collaborator: $e')),
      );
    }
  }
}

Future<void> showRemoveCollaboratorDialog(BuildContext context, String boardId) async
{
  String? collaboratorEmail = await showDialog<String>(
    context: context,
    builder: (context) {
      return AlertDialog(
        title: const Text('Remove Collaborator'),
        content: TextField(
          decoration: const InputDecoration(hintText: 'Collaborator Email'),
          onSubmitted: (value) {
            Navigator.of(context).pop(value);
          },
        ),
      );
    },
  );

  if (collaboratorEmail != null && collaboratorEmail.isNotEmpty) {
    try {
      await Provider.of<BoardProvider>(context, listen: false)
          .removeCollaborator(boardId, collaboratorEmail);
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('Collaborator removed successfully!')),
      );
    } catch (e) {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text('Error removing collaborator: $e')),
      );
    }
  }
}
