import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'menu.dart';
import 'board_provider.dart';
import 'user.dart';
import 'board_view.dart';

class HomePage extends StatefulWidget {
  const HomePage({Key? key}) : super(key: key);

  @override
  _HomePageState createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  final PageController _templatePageController = PageController(viewportFraction: 0.4);
  final PageController _myBoardsPageController = PageController(viewportFraction: 0.4);
  final PageController _collabBoardsPageController = PageController(viewportFraction: 0.4);

  final List<String> templateItems = ['Template 1', 'Template 2', 'Template 3'];
  final List<String> collaborationBoards = ['Collab Board 1', 'Collab Board 2', 'Collab Board 3', 'Collab Board 4'];

  late Future<List<Board>> _fetchBoardsFuture;
  late int userId;

  final TextEditingController _newTemplateController = TextEditingController();

  @override
  void initState() {
    super.initState();
    userId = Provider.of<UserProvider>(context, listen: false).user?.userId ?? 0;
    _fetchBoardsFuture = Provider.of<BoardProvider>(context, listen: false).fetchBoards(userId);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Row(
        children: [
          const SideMenu(),
          Expanded(
            child: Padding(
              padding: const EdgeInsets.all(16.0),
              child: ListView(
                children: [
                  _buildTemplateSection(),
                  const SizedBox(height: 40),
                  _buildMyBoardsSection(), // Load My Boards dynamically
                  const SizedBox(height: 40),
                  _buildSection(
                    title: 'Collaboration Boards',
                    items: collaborationBoards,
                    pageController: _collabBoardsPageController,
                    onItemClick: (item) => print('Collaboration Board selected: $item'),
                  ),
                ],
              ),
            ),
          ),
        ],
      ),
    );
  }

  Widget _buildMyBoardsSection() {
    return FutureBuilder<List<Board>>(
      future: _fetchBoardsFuture,
      builder: (context, snapshot) {
        if (snapshot.connectionState == ConnectionState.waiting) {
          return const Center(child: CircularProgressIndicator());
        } else if (snapshot.hasError) {
          return Center(child: Text('Error: ${snapshot.error}', style: TextStyle(color: Colors.red)));
        } else if (!snapshot.hasData || snapshot.data!.isEmpty) {
          return const Center(child: Text('No boards available', style: TextStyle(fontSize: 18)));
        } else {
          return _buildBoardSection(
            title: 'My Boards',
            boards: snapshot.data!, // Pass the list of Board objects
          );
        }
      },
    );
  }

  Widget _buildBoardSection({required String title, required List<Board> boards}) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text(
          title,
          style: const TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
        ),
        const SizedBox(height: 16),
        Stack(
          alignment: Alignment.center,
          children: [
            SizedBox(
              height: 200, // Adjust as needed
              child: PageView.builder(
                controller: _myBoardsPageController,
                itemCount: boards.length,
                itemBuilder: (context, index) {
                  final board = boards[index];
                  return GestureDetector(
                    onTap: () {
                      Navigator.push(
                        context,
                        MaterialPageRoute(
                          builder: (context) => BoardView(board: board),
                        ),
                      );
                    },
                    child: Card(
                      margin: const EdgeInsets.symmetric(horizontal: 8),
                      elevation: 4,
                      shape: RoundedRectangleBorder(
                        borderRadius: BorderRadius.circular(12),
                      ),
                      child: Center(
                        child: Padding(
                          padding: const EdgeInsets.all(16.0),
                          child: Text(
                            board.title, // Display board title
                            textAlign: TextAlign.center,
                            style: const TextStyle(fontSize: 18),
                          ),
                        ),
                      ),
                    ),
                  );
                },
              ),
            ),
            Positioned(
              left: 0,
              child: IconButton(
                icon: const Icon(Icons.arrow_back),
                tooltip: 'Previous',
                onPressed: () {
                  _myBoardsPageController.previousPage(
                    duration: const Duration(milliseconds: 300),
                    curve: Curves.easeInOut,
                  );
                },
              ),
            ),
            Positioned(
              right: 0,
              child: IconButton(
                icon: const Icon(Icons.arrow_forward),
                tooltip: 'Next',
                onPressed: () {
                  _myBoardsPageController.nextPage(
                    duration: const Duration(milliseconds: 300),
                    curve: Curves.easeInOut,
                  );
                },
              ),
            ),
          ],
        ),
      ],
    );
  }

  Widget _buildTemplateSection() {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        const Text(
          'Templates',
          style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
        ),
        const SizedBox(height: 16),
        Stack(
          alignment: Alignment.center,
          children: [
            SizedBox(
              height: 200, // Adjust as needed
              child: PageView.builder(
                controller: _templatePageController,
                itemCount: templateItems.length,
                itemBuilder: (context, index) {
                  final item = templateItems[index];
                  return GestureDetector(
                    onTap: () async {
                      // Trigger creation of the board
                      final boardProvider = Provider.of<BoardProvider>(context, listen: false);
                      try {
                        await boardProvider.createBoardFromTemplate(
                          boardName: '$item Board',  // Dynamic board name
                          userId: userId,
                          templateId: index + 1,  // Template ID, adjust based on your template data
                        );

                        // Optionally, refresh the list or navigate
                        ScaffoldMessenger.of(context).showSnackBar(
                          SnackBar(content: Text('$item board created!')),
                        );
                      } catch (e) {
                        // Handle error
                        ScaffoldMessenger.of(context).showSnackBar(
                          SnackBar(content: Text('Error: $e')),
                        );
                      }
                    },
                    child: Card(
                      margin: const EdgeInsets.symmetric(horizontal: 8),
                      elevation: 4,
                      shape: RoundedRectangleBorder(
                        borderRadius: BorderRadius.circular(12),
                      ),
                      child: Center(
                        child: Padding(
                          padding: const EdgeInsets.all(16.0),
                          child: Text(
                            item,
                            textAlign: TextAlign.center,
                            style: const TextStyle(fontSize: 18),
                          ),
                        ),
                      ),
                    ),
                  );
                },
              ),
            ),
            Positioned(
              left: 0,
              child: IconButton(
                icon: const Icon(Icons.arrow_back),
                tooltip: 'Previous',
                onPressed: () {
                  _templatePageController.previousPage(
                    duration: const Duration(milliseconds: 300),
                    curve: Curves.easeInOut,
                  );
                },
              ),
            ),
            Positioned(
              right: 0,
              child: IconButton(
                icon: const Icon(Icons.arrow_forward),
                tooltip: 'Next',
                onPressed: () {
                  _templatePageController.nextPage(
                    duration: const Duration(milliseconds: 300),
                    curve: Curves.easeInOut,
                  );
                },
              ),
            ),
          ],
        ),
        const SizedBox(height: 16),
        TextField(
          controller: _newTemplateController,
          decoration: InputDecoration(
            labelText: 'New Template Name',
            border: OutlineInputBorder(),
          ),
        ),
        ElevatedButton(
          onPressed: () {
            final newTemplateName = _newTemplateController.text.trim();
            if (newTemplateName.isNotEmpty) {
              setState(() {
                templateItems.add(newTemplateName);  // Add new template to the list
                _newTemplateController.clear();  // Clear the input field
              });
            }
          },
          child: const Text('Add Template'),
        ),
      ],
    );
  }

  /// General function to build a section (used for Templates and Collab Boards)
  Widget _buildSection({
    required String title,
    required List<String> items,
    required PageController pageController,
    required Function(String) onItemClick,
  }) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text(
          title,
          style: const TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
        ),
        const SizedBox(height: 16),
        Stack(
          alignment: Alignment.center,
          children: [
            SizedBox(
              height: 200, // Adjust the height as needed
              child: PageView.builder(
                controller: pageController,
                itemCount: items.length,
                itemBuilder: (context, index) {
                  return GestureDetector(
                    onTap: () => onItemClick(items[index]),
                    child: Card(
                      margin: const EdgeInsets.symmetric(horizontal: 8),
                      elevation: 4,
                      shape: RoundedRectangleBorder(
                        borderRadius: BorderRadius.circular(12),
                      ),
                      child: Center(
                        child: Padding(
                          padding: const EdgeInsets.all(16.0),
                          child: Text(
                            items[index],
                            textAlign: TextAlign.center,
                            style: const TextStyle(fontSize: 18),
                          ),
                        ),
                      ),
                    ),
                  );
                },
              ),
            ),
            Positioned(
              left: 0,
              child: IconButton(
                icon: const Icon(Icons.arrow_back),
                tooltip: 'Previous',
                onPressed: () {
                  pageController.previousPage(
                    duration: const Duration(milliseconds: 300),
                    curve: Curves.easeInOut,
                  );
                },
              ),
            ),
            Positioned(
              right: 0,
              child: IconButton(
                icon: const Icon(Icons.arrow_forward),
                tooltip: 'Next',
                onPressed: () {
                  pageController.nextPage(
                    duration: const Duration(milliseconds: 300),
                    curve: Curves.easeInOut,
                  );
                },
              ),
            ),
          ],
        ),
      ],
    );
  }
}
