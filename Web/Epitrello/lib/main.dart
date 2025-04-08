import 'package:epitrello/home.dart';
import 'package:epitrello/landing_page.dart';
import 'package:epitrello/settings.dart';
import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'login.dart';
import 'register.dart';
import 'workspace.dart';
import 'user.dart';
import 'board_provider.dart';
import 'notifications.dart';
import 'landing_page.dart';

void main() {
  runApp(
    MultiProvider(
      providers: [
        ChangeNotifierProvider(create: (context) => UserProvider()),
        ChangeNotifierProvider(create: (context) => BoardProvider()),
      ],
      child: const MyApp(),
    ),
  );
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'EpiTrello',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      initialRoute: '/landing',
      routes: {
        '/landing': (context) => const LandingPage(),
        '/login': (context) => const LoginPage(),
        '/register': (context) => const RegisterPage(),
        '/home': (context) => const HomePage(),
        '/workspace': (context) => const WorkspacePage(),
        '/settings': (context) => SettingsPage(),
        '/notifications': (context) => const NotificationsPage(),
        }
    );
  }
}
