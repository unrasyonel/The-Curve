
import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

void onPressed() {
    print("Logout button pressed");  
}

void onMenuPressed() {
    print("Logout button pressed");  
}

  @override
  Widget build(BuildContext context) {
    return MaterialApp(  
      home: Scaffold(
        backgroundColor: Colors.green[500],
        appBar: AppBar(
          backgroundColor: Colors.green[700],
            title: Text(
              "RandomAss",
              style: TextStyle(
                color: Colors.white,
                fontSize: 20,
                fontFamily: 'Papyrus',
                fontWeight: FontWeight.bold,
              ),
          ),
          leading: IconButton(  
            icon: Icon(Icons.menu, color: Colors.white),
            onPressed: onMenuPressed,),

          actions: [IconButton(onPressed: onPressed, icon: Icon(Icons.accessible_forward_rounded,
          color: Colors.white))],
        ),

        body: Center(
          child: Container(
            height: 100,
            width: 100,
            padding: const EdgeInsets.all(20),
            decoration: BoxDecoration(
              color: Colors.green[700],
              borderRadius: BorderRadius.circular(40),
            ),
            child: Center(
              child: const Text(
                "touch me",
                style: TextStyle(
                  color: Colors.white,
                  fontSize: 20,
                  fontFamily: 'Papyrus',
                  fontWeight: FontWeight.bold,
                ),
              ),
            ),
          ),
        ),
      ),
      debugShowCheckedModeBanner: false,
    );
  }
}
