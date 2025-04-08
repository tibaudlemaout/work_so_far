import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'user.dart';

class SideMenu extends StatelessWidget {
  const SideMenu({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final user = Provider.of<UserProvider>(context).user;

    return Container(
      width: 250,
      decoration: BoxDecoration(
        color: Colors.blue.shade800,
        borderRadius: const BorderRadius.only(
          topRight: Radius.circular(16),
          bottomRight: Radius.circular(16),
        ),
      ),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          // Menu header with profile info
          Container(
            padding: const EdgeInsets.all(16.0),
            decoration: BoxDecoration(
              color: Colors.blue.shade700,
              borderRadius: const BorderRadius.only(
                topRight: Radius.circular(16),
              ),
              boxShadow: [
                BoxShadow(
                  color: Colors.black.withOpacity(0.2),
                  blurRadius: 6,
                  offset: const Offset(0, 3),
                ),
              ],
            ),
            child: Row(
              children: [
                CircleAvatar(
                  radius: 24,
                  backgroundColor: Colors.white,
                  child: Icon(
                    Icons.person,
                    size: 32,
                    color: Colors.blue.shade800,
                  ),
                ),
                const SizedBox(width: 16),
                Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Text(
                      '${user?.username ?? 'Guest'}',
                      style: const TextStyle(
                        color: Colors.white,
                        fontSize: 18,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                    Text(
                      '${user?.email ?? 'No email'}',
                      style: const TextStyle(
                        color: Colors.white70,
                        fontSize: 14,
                      ),
                    ),
                  ],
                ),
              ],
            ),
          ),
          const SizedBox(height: 20),
          // Menu items
          Expanded(
            child: ListView(
              children: const [
                MenuItem(
                  icon: Icons.home,
                  label: 'Home',
                  routeName: '/home',
                ),
                MenuItem(
                  icon: Icons.work,
                  label: 'Workspaces',
                  routeName: '/workspace',
                ),
                MenuItem(
                  icon: Icons.dashboard,
                  label: 'Boards',
                  routeName: '/workspace',
                ),
                MenuItem(
                  icon: Icons.notifications,
                  label: 'Notifications',
                  routeName: '/notifications',
                ),
                MenuItem(
                  icon: Icons.settings,
                  label: 'Settings',
                  routeName: '/settings',
                ),
                MenuItem(
                  icon: Icons.logout,
                  label: 'Logout',
                  routeName: '/login',
                ),
              ],
            ),
          ),
        ],
      ),
    );
  }
}

class MenuItem extends StatefulWidget {
  final IconData icon;
  final String label;
  final String routeName;

  const MenuItem({
    required this.icon,
    required this.label,
    required this.routeName,
    Key? key,
  }) : super(key: key);

  @override
  _MenuItemState createState() => _MenuItemState();
}

class _MenuItemState extends State<MenuItem> {
  bool _isHovered = false;

  @override
  Widget build(BuildContext context) {
    return MouseRegion(
      onEnter: (_) => setState(() => _isHovered = true),
      onExit: (_) => setState(() => _isHovered = false),
      child: InkWell(
        onTap: () {
          Navigator.pushNamed(context, widget.routeName);
        },
        child: AnimatedContainer(
          duration: const Duration(milliseconds: 200),
          decoration: BoxDecoration(
            color: _isHovered ? Colors.blue.shade700 : Colors.transparent,
            borderRadius: BorderRadius.circular(8),
          ),
          padding: const EdgeInsets.symmetric(vertical: 12.0, horizontal: 16.0),
          child: Row(
            children: [
              Icon(widget.icon, color: Colors.white),
              const SizedBox(width: 16),
              Expanded(
                child: Text(
                  widget.label,
                  style: const TextStyle(
                    color: Colors.white,
                    fontSize: 16,
                    fontWeight: FontWeight.w500,
                  ),
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
