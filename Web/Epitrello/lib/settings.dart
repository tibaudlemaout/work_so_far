import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'menu.dart';
import 'user.dart';

class SettingsPage extends StatefulWidget {
  @override
  _SettingsPageState createState() => _SettingsPageState();
}

class _SettingsPageState extends State<SettingsPage> {
  // Controllers for password change
  TextEditingController _currentPasswordController = TextEditingController();
  TextEditingController _newPasswordController = TextEditingController();

  // Variables for user settings
  bool _emailNotifications = true;
  bool _pushNotifications = true;
  bool _darkMode = false;
  bool _twoFactorAuth = false;
  String _teamRole = "Member";

  @override
  Widget build(BuildContext context) {
    User? user = Provider.of<UserProvider>(context).user;

    if (user == null) {
      Future.microtask(() {
        Navigator.pushReplacementNamed(context, '/login');
      });
      return Scaffold(
        body: Center(child: CircularProgressIndicator()),
      );
    }

    return Scaffold(
      body: Row(
        children: [
          SideMenu(),
          Expanded(
            child: SingleChildScrollView(
              padding: const EdgeInsets.all(16.0),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  _buildSectionCard(
                    'Account Information',
                    [
                      _buildAccountDetailRow('Username', user.username, () {
                        _showEditDialog(context, 'Username', user.username);
                      }),
                      _buildAccountDetailRow('Email', user.email, () {
                        _showEditDialog(context, 'Email', user.email);
                      }),
                      ElevatedButton(
                        onPressed: () {
                          _showChangePasswordDialog(context);
                        },
                        child: Text('Change Password'),
                      ),
                    ],
                  ),
                  _buildSectionCard(
                    'Notification Settings',
                    [
                      _buildSwitchRow('Email Notifications', _emailNotifications, (value) {
                        setState(() {
                          _emailNotifications = value;
                        });
                      }),
                      _buildSwitchRow('Push Notifications', _pushNotifications, (value) {
                        setState(() {
                          _pushNotifications = value;
                        });
                      }),
                    ],
                  ),
                  _buildSectionCard(
                    'Display Settings',
                    [
                      _buildSwitchRow('Dark Mode', _darkMode, (value) {
                        setState(() {
                          _darkMode = value;
                        });
                      }),
                    ],
                  ),
                  _buildSectionCard(
                    'Security Settings',
                    [
                      _buildSwitchRow('Two-Factor Authentication', _twoFactorAuth, (value) {
                        setState(() {
                          _twoFactorAuth = value;
                        });
                      }),
                    ],
                  ),
                  _buildSectionCard(
                    'Team Settings',
                    [
                      _buildDropdownRow('Role in Team', _teamRole, ['Member', 'Admin', 'Guest'], (newValue) {
                        setState(() {
                          _teamRole = newValue!;
                        });
                      }),
                    ],
                  ),
                ],
              ),
            ),
          ),
        ],
      ),
    );
  }

  Widget _buildSectionCard(String title, List<Widget> children) {
    return Card(
      elevation: 4,
      margin: const EdgeInsets.only(bottom: 16.0),
      child: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Text(
              title,
              style: TextStyle(fontSize: 22, fontWeight: FontWeight.bold),
            ),
            SizedBox(height: 16),
            ...children,
          ],
        ),
      ),
    );
  }

  Widget _buildAccountDetailRow(String label, String value, VoidCallback onEdit) {
    return Row(
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
      children: [
        Text('$label: $value', style: TextStyle(fontSize: 18)),
        TextButton(
          onPressed: onEdit,
          child: Text('Edit'),
        ),
      ],
    );
  }

  Widget _buildSwitchRow(String label, bool value, ValueChanged<bool> onChanged) {
    return Row(
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
      children: [
        Text(label, style: TextStyle(fontSize: 18)),
        Switch(value: value, onChanged: onChanged),
      ],
    );
  }

  Widget _buildDropdownRow(String label, String value, List<String> options, ValueChanged<String?> onChanged) {
    return Row(
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
      children: [
        Text(label, style: TextStyle(fontSize: 18)),
        DropdownButton<String>(
          value: value,
          onChanged: onChanged,
          items: options.map((option) {
            return DropdownMenuItem<String>(
              value: option,
              child: Text(option),
            );
          }).toList(),
        ),
      ],
    );
  }

  // Function to show a dialog for editing username or email
  void _showEditDialog(BuildContext context, String field, String currentValue) {
    TextEditingController controller = TextEditingController(text: currentValue);

    showDialog(
      context: context,
      builder: (context) {
        return AlertDialog(
          title: Text('Change $field'),
          content: TextField(
            controller: controller,
            decoration: InputDecoration(
              labelText: field,
            ),
          ),
          actions: [
            TextButton(
              onPressed: () {
                Navigator.pop(context);
              },
              child: Text('Cancel'),
            ),
            TextButton(
              onPressed: () {
                if (controller.text.isNotEmpty) {
                  // Update the user object in the provider
                  Provider.of<UserProvider>(context, listen: false).updateUserField(field, controller.text);
                  Provider.of<UserProvider>(context, listen: false).updateUsername(controller.text);
                  Navigator.pop(context);
                  ScaffoldMessenger.of(context).showSnackBar(
                    SnackBar(content: Text('$field updated successfully')),
                  );
                }
              },
              child: Text('Save'),
            ),
          ],
        );
      },
    );
  }

  // Function to show the password change dialog
  void _showChangePasswordDialog(BuildContext context) {
    showDialog(
      context: context,
      builder: (context) {
        return AlertDialog(
          title: Text('Change Password'),
          content: Column(
            mainAxisSize: MainAxisSize.min,
            children: [
              TextField(
                controller: _currentPasswordController,
                obscureText: true,
                decoration: InputDecoration(labelText: 'Current Password'),
              ),
              TextField(
                controller: _newPasswordController,
                obscureText: true,
                decoration: InputDecoration(labelText: 'New Password'),
              ),
            ],
          ),
          actions: [
            TextButton(
              onPressed: () {
                Navigator.pop(context);
              },
              child: Text('Cancel'),
            ),
            TextButton(
              onPressed: () {
                String currentPassword = _currentPasswordController.text;
                String newPassword = _newPasswordController.text;
                if (currentPassword.isNotEmpty && newPassword.isNotEmpty) {
                  ScaffoldMessenger.of(context).showSnackBar(
                    SnackBar(content: Text('Password changed successfully')),
                  );
                  Navigator.pop(context);
                }
              },
              child: Text('Save'),
            ),
          ],
        );
      },
    );
  }
}
