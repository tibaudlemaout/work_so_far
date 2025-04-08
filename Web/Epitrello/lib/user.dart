import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;
import 'dart:convert';

class User {
  int userId; // The user's unique ID
  String username; // The user's username
  String email; // The user's email address

  // Constructor to create a User object
  User({
    required this.userId, // Required parameter for user ID
    required this.username, // Required parameter for username
    required this.email, // Required parameter for email
  });
}

class UserProvider extends ChangeNotifier {
  User? _user;

  User? get user => _user;

  void setUser(User user) {
    _user = user;
    notifyListeners();
  }

  void updateUserField(String field, String newValue)
  {
    if (user == null) return;

    if (field == 'Username') {
      user!.username = newValue;
    } else if (field == 'Email') {
      user!.email = newValue;
    }
  }

  Future<bool> updateUsername(String newUsername) async
  {
    if (_user == null || _user!.username == newUsername) {
      return false;  // No need to update if the username is the same
    }

    print('Sending update request: user_id = ${_user!.userId}, new_username = $newUsername');

    const url = 'http://localhost:3000/update-username';
    final response = await http.put(
      Uri.parse(url),
      headers: {'Content-Type': 'application/json'},
      body: json.encode({
        'user_id': _user!.userId,
        'new_username': newUsername,
      }),
    );

    print('Response status: ${response.statusCode}');
    print('Response body: ${response.body}');

    if (response.statusCode == 200) {
      // Successfully updated the username in the database
      _user = User(userId: _user!.userId, username: newUsername, email: _user!.email);
      notifyListeners();  // Notify listeners to update the UI
      return true;
    } else {
      return false;
    }
  }
}