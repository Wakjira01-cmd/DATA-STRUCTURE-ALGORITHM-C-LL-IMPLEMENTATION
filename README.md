# DATA-STRUCTURE-ALGORITHM-C-LL-IMPLEMENTATION
Linked List Implementations in C++
This repository contains implementations of four types of linked lists in C++. Each implementation includes various operations to manage student data effectively.

Types of Linked Lists
1. Singly Linked List
A Singly Linked List is a data structure where each node contains data and a pointer to the next node in the sequence. This implementation allows for various operations on student data.

2. Doubly Linked List
A Doubly Linked List is a linear data structure where each node contains pointers to both the next and previous nodes. This allows for bidirectional traversal of the list.

3. Circular Singly Linked List
In a Circular Singly Linked List, the last node points back to the first node, creating a circular structure. This allows for continuous traversal of the list without needing to reach a null pointer.

4. Circular Doubly Linked List
A Circular Doubly Linked List combines the features of both circular and doubly linked lists. Here, the last node points to the first node, and the first node points back to the last node, allowing for bidirectional traversal in a circular manner.

Operations Overview
Each linked list implementation provides the following typical operations:

Insertion: Add student data at the beginning, end, or a specific position.
Deletion: Remove student data from the beginning, end, or a specific position.
Searching: Find a student by their unique identifier (e.g., ID).
Display: Print the list of all students.
Singly Linked List Menu


1. Insert at beginning
2. Insert at end
3. Insert at position
4. Delete from beginning
5. Delete from end
6. Delete from position
7. Search for element
8. Display list
9. Exit
Doubly Linked List Menu


1. Insert at beginning
2. Insert at end
3. Insert at position
4. Delete from beginning
5. Delete from end
6. Delete from position
7. Search for element
8. Display list
9. Exit
Circular Singly Linked List Menu


1. Insert at beginning
2. Insert at end
3. Insert at position
4. Delete from beginning
5. Delete from end
6. Delete from position
7. Search for element
8. Display list
9. Exit
Circular Doubly Linked List Menu


1. Insert at beginning
2. Insert at end
3. Insert at position
4. Delete from beginning
5. Delete from end
6. Delete from position
7. Search for element
8. Display list
9. Exit
Features
Deletions
Remove nodes from the beginning, end, or any specified position.
Searching
Locate a node using a unique identifier (e.g., student ID).
Display
Print all nodes in the list, showing their details.
Compiling and Running in Dev-C++
To compile and run the C++ programs using Dev-C++, ensure the following:

Prerequisites
Dev-C++ is installed on your computer. You can download it from the Dev-C++ Website.
Your computer meets the system requirements for running Dev-C++.
Steps to Use the Code
Open Dev-C++: Launch the IDE on your computer.
Write the Code: Copy and paste the code into a new .cpp file.
Save the File: Save the file with a .cpp extension (e.g., linked_list.cpp).
Compile the Code: Go to Execute &gt; Compile (or press F9) to check for errors during compilation.
Run the Program: Click Run &gt; Execute (or press F10) to run the program and see the output.
Example Usage
After running the program, you will see a menu. Here are some example interactions:

Insert Data at Beginning:


Your choice: 1
Enter name: WAKJIRA
Enter age: 24
Enter ID: 20996
Output: Successfully added at beginning.

Insert Data at End:


Your choice: 2
Enter name: CHALA
Enter age: 23
Enter ID: 20934
Output: Successfully added at end.

Display Student List:


Your choice: 8
Output:



Student List:
     Student 1:
     Name: WAKJIRA
     Age: 24
     ID: 20996
     Student 2:
     Name: CHALA
     Age: 23
     ID: 20934
Delete Data:


Your choice: 4
Output: _Deleted: WAKJIRA_

Display Empty List:


Your choice: 8
Output: List is empty!

Note
The program is designed to handle invalid input gracefully. If you enter symbols or incorrect data types, the program will not terminate unexpectedly.

Acknowledgements
Instructor: Mr. Lencho Desalegn (MSc.) - Data Structures and Algorithms
References: Jenny Lecture Videos, AIO, and Universal Tube.
This version of the README is structured in a way that makes it easy for users to understand the purpose, functionality, and usage of the linked list implementations. Each section is clearly defined, and the information is presented in a logical flow. Feel free to adjust any parts further to better fit your project's needs!
