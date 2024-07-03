import 'package:flutter/material.dart';

class TodoTile extends StatelessWidget {
  final String taskName;
  final bool taskCompleted;
  final Function(bool?)? onChanged;

  TodoTile({
    super.key,
    required this.taskName,
    required this.taskCompleted,
    required this.onChanged,
  });

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.only(right: 25.0, left: 25.00, top: 25.0),
      child: Container(
        padding: EdgeInsets.all(24),
        child: Row(
          children: [
            Checkbox(
              value: taskCompleted,
              onChanged: onChanged,
              activeColor: Colors.teal[900],
            ),

            Text(
              taskName,
              style: TextStyle(decoration: taskCompleted
              ? TextDecoration.lineThrough
              : TextDecoration.none)
            ),

          ],
        ),
        decoration: BoxDecoration(
          color: Colors.teal,
          borderRadius: BorderRadius.circular(10),
        ),
      ),
    );
  }
}
