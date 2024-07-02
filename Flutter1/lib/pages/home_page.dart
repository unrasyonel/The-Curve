import 'package:fitness/utilities/todo_tile.dart';
import 'package:flutter/material.dart';

class HomePage extends StatefulWidget {

  const HomePage({super.key});

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.teal[400],
      appBar: AppBar(
        title: Text("TO DO"),
        backgroundColor: Colors.teal,
        
        
      ),

    body: ListView(
      children: [
        TodoTile(
          taskName: "Artvin oyna.",
          taskCompleted: true,
          onChanged: (p0) {},
        ),

        TodoTile(taskName: "Biraz daha Artvin oyna.",
         taskCompleted: false, 
         onChanged: (p1) {}),
        
        TodoTile(taskName: "DAHA FAZLA Artvin oyna.",
         taskCompleted: true, 
         onChanged: (p1) {}),
        
      ],

    ),

    );
  }
}