import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'user.dart';
import 'dart:convert';
import 'package:http/http.dart' as http;
import 'menu.dart';

class NotificationsPage extends StatefulWidget {
  const NotificationsPage({Key? key}) : super(key: key);

  @override
  _NotificationsPageState createState() => _NotificationsPageState();
}

class _NotificationsPageState extends State<NotificationsPage> {
  List<dynamic> notifications = [];
  bool isLoading = true;

  @override
  void initState() {
    super.initState();
    fetchNotifications();
  }

  Future<void> fetchNotifications() async {
  final userId = Provider.of<UserProvider>(context, listen: false).user?.userId;
  if (userId == null) {
    print('Error: User ID is null');
    return;
  }

  final url = 'http://localhost:3000/notifications/$userId';
  try {
    final response = await http.get(Uri.parse(url));
    print('Response Status: ${response.statusCode}'); 
    print('Response Body: ${response.body}'); // Log the response body

    if (response.statusCode == 200) {
      final data = jsonDecode(response.body);

      // Check the structure of 'notifications'
      if (data['success'] && data['notifications'] is List) {
        setState(() {
          notifications = data['notifications'];
          isLoading = false;
        });
      } else {
        print('Error: Notifications data is not a list.');
        setState(() {
          isLoading = false;
        });
      }
    } else {
      throw Exception('Failed to load notifications');
    }
  } catch (e) {
    print('Error: $e');
    setState(() {
      isLoading = false;
    });
  }
}

  Future<void> markAsRead(int notificationId) async {
    final url = 'http://localhost:3000/notifications/$notificationId/mark-as-read';

    try {
      final response = await http.post(Uri.parse(url));

      if (response.statusCode == 200) {
        print('Notification $notificationId marked as read.');
      } else {
        print('Failed to mark notification as read: ${response.body}');
      }
    } catch (e) {
      print('Error marking notification as read: $e');
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Row(
        children: [
          SideMenu(),
          Expanded(
            child: Padding(
              padding: const EdgeInsets.all(16.0),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  const Text(
                    'Notifications',
                    style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
                  ),
                  SizedBox(height: 20),
                  isLoading
                      ? const Center(child: CircularProgressIndicator())
                      : notifications.isEmpty
                          ? const Center(child: Text('No notifications yet.'))
                          : Expanded(
                              child: ListView.builder(
                                itemCount: notifications.length,
                                itemBuilder: (context, index) {
                                  try {
                                    final notification = notifications[index];

                                    return ListTile(
                                      title: Text(notification['type'] ?? 'Notification'),
                                      subtitle: Text(notification['message']),
                                      trailing: notification['read'] == 1
                                          ? const Icon(Icons.check, color: Colors.green)
                                          : const Icon(Icons.notifications, color: Colors.red),
                                      onTap: () {
                                        // Update the local notification's `read` status
                                        setState(() {
                                          notifications[index]['read'] = 1;
                                        });
                                        markAsRead(notification['notification_id']);
                                      },
                                    );
                                  } catch (e) {
                                    print('Error building list item: $e');
                                    return const ListTile(
                                      title: Text('Error loading notification'),
                                    );
                                  }
                                },
                              )

                            ),
                ],
              ),
            ),
          ),
        ],
      ),
    );
  }
}