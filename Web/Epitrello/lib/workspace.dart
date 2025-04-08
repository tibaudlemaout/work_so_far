import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'menu.dart';
import 'board_view.dart';
import 'board_provider.dart';
import 'user.dart';

class WorkspacePage extends StatefulWidget {
  const WorkspacePage({Key? key}) : super(key: key);

  @override
  _WorkspacePageState createState() => _WorkspacePageState();
}

class _WorkspacePageState extends State<WorkspacePage> {
  late Future<List<Board>> _fetchBoardsFuture;
  late int userId;

  @override
  void initState() {
    super.initState();
    userId = Provider.of<UserProvider>(context, listen: false).user?.userId ?? 0;
    _fetchBoardsFuture = Provider.of<BoardProvider>(context, listen: false).fetchBoards(userId);
  }

  @override
  Widget build(BuildContext context) {
    final boardProvider = Provider.of<BoardProvider>(context);

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
                  // Header
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      const Text(
                        'Your Boards',
                        style: TextStyle(fontSize: 28, fontWeight: FontWeight.bold, color: Colors.blue),
                      ),
                      ElevatedButton.icon(
                        onPressed: _createNewBoard,
                        icon: const Icon(Icons.add),
                        label: const Text('Create New Board'),
                        style: ElevatedButton.styleFrom(
                          backgroundColor: Colors.blue, // Consistent button color
                          foregroundColor: Colors.white,
                          padding: const EdgeInsets.symmetric(vertical: 12.0, horizontal: 16.0),
                          shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(8.0)),
                        ),
                      ),
                    ],
                  ),
                  const SizedBox(height: 20),

                  // Boards Grid
                  Expanded(
                    child: FutureBuilder<List<Board>>(
                      future: _fetchBoardsFuture,
                      builder: (context, snapshot) {
                        if (snapshot.connectionState == ConnectionState.waiting) {
                          return const Center(child: CircularProgressIndicator());
                        } else if (snapshot.hasError) {
                          return Center(child: Text('Error: ${snapshot.error}', style: TextStyle(color: Colors.red)));
                        } else if (!snapshot.hasData || snapshot.data!.isEmpty) {
                          return const Center(child: Text('No boards available', style: TextStyle(fontSize: 18)));
                        } else {
                          return GridView.builder(
                            gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
                              crossAxisCount: 2,
                              crossAxisSpacing: 16,
                              mainAxisSpacing: 16,
                              childAspectRatio: 1.5,
                            ),
                            itemCount: snapshot.data!.length,
                            itemBuilder: (context, index) {
                              final board = snapshot.data![index];
                              return InkWell(
                                onTap: () {
                                  Navigator.push(
                                    context,
                                    MaterialPageRoute(
                                      builder: (context) => BoardView(board: board),
                                    ),
                                  );
                                },
                                child: Card(
                                  elevation: 6,
                                  shape: RoundedRectangleBorder(
                                    borderRadius: BorderRadius.circular(12),
                                  ),
                                  child: Container(
                                    padding: const EdgeInsets.all(16),
                                    decoration: BoxDecoration(
                                      gradient: LinearGradient(
                                        colors: [Colors.blue.shade200, Colors.blue.shade400],
                                        begin: Alignment.topLeft,
                                        end: Alignment.bottomRight,
                                      ),
                                      borderRadius: BorderRadius.circular(12),
                                    ),
                                    child: Center(
                                      child: Text(
                                        board.title,
                                        style: const TextStyle(
                                          fontSize: 18,
                                          color: Colors.white,
                                          fontWeight: FontWeight.w600,
                                        ),
                                        textAlign: TextAlign.center,
                                      ),
                                    ),
                                  ),
                                ),
                              );
                            },
                          );
                        }
                      },
                    ),
                  ),
                ],
              ),
            ),
          ),
        ],
      ),
    );
  }

  Future<void> _createNewBoard() async {
    final boardProvider = Provider.of<BoardProvider>(context, listen: false);
    String? newBoardName = await showDialog<String>(
      context: context,
      builder: (context) {
        String? boardName;
        return AlertDialog(
          title: const Text('Create New Board'),
          content: TextField(
            autofocus: true,
            decoration: const InputDecoration(
              hintText: 'Board Name',
              border: OutlineInputBorder(),
            ),
            onChanged: (value) => boardName = value,
          ),
          actions: [
            TextButton(
              onPressed: () => Navigator.of(context).pop(),
              child: const Text('Cancel'),
            ),
            ElevatedButton(
              onPressed: () => Navigator.of(context).pop(boardName),
              child: const Text('Create'),
              style: ElevatedButton.styleFrom(
                backgroundColor: Colors.blue,
                foregroundColor: Colors.white,
              ),
            ),
          ],
        );
      },
    );

    if (newBoardName != null && newBoardName.isNotEmpty) {
      await boardProvider.createBoard(newBoardName, userId);
      final updatedBoards = await boardProvider.fetchBoards(userId);
      setState(() {
        _fetchBoardsFuture = Future.value(updatedBoards);
      });
    }
  }
}
