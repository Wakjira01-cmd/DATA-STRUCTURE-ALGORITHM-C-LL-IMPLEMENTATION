#include <iostream>   // Include the input/output stream library
#include <string>     // Include the string library
using namespace std;  // Use the standard namespace

// Define a Student structure to represent each node in the linked list
struct Student {
    string name;    // Student's name
    int age;        // Student's age
    int id;         // Student's ID
    Student* next;  // Pointer to the next student in the list
};

Student* head = NULL;  // Global pointer to the first element of the linked list (initially empty)

// Function prototypes
void displayMenu();            // Displays the main menu
void insertAtBeginning();      // Inserts a student at the beginning of the list
void insertAtEnd();            // Inserts a student at the end of the list
void insertAtPosition();       // Inserts a student at a specific position
void deleteFromBeginning();     // Deletes the first student
void deleteFromEnd();           // Deletes the last student
void deleteFromPosition();      // Deletes a student from a specific position
void searchForElement();        // Searches for a student by ID
void displayList();             // Displays all students in the list
void deleteList();              // Helper function to free all memory used by the list

int main() {
    displayMenu();     // Start the program by displaying the menu
    deleteList();      // Clean up memory before exiting
    return 0;          // Return 0 to indicate successful execution
}

// Displays the main menu and handles user input
void displayMenu() {
    int choice;  // Variable to store user's menu choice
    
    do {
        // Display menu options
        cout << "\nSINGLY LINKED LIST MENU\n"
             << "1. Insert at beginning\n"
             << "2. Insert at end\n"
             << "3. Insert at position\n"
             << "4. Delete from beginning\n"
             << "5. Delete from end\n"
             << "6. Delete from position\n"
             << "7. Search for element\n"
             << "8. Display list\n"
             << "9. Exit\n"
             << "----------------------\nYour choice: ";
        cin >> choice;  // Get user's choice

        // Execute the appropriate function based on user's choice
        switch (choice) {
            case 1: insertAtBeginning(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtPosition(); break;
            case 4: deleteFromBeginning(); break;
            case 5: deleteFromEnd(); break;
            case 6: deleteFromPosition(); break;
            case 7: searchForElement(); break;
            case 8: displayList(); break;
            case 9: cout << "Exiting program.\n"; break;
            default: cout << "Invalid option! Please try again.\n";
        }
    } while (choice != 9);  // Continue until user chooses to exit
}

// Inserts a new student at the beginning of the list
void insertAtBeginning() {
    Student* newStudent = new Student;  // Create a new student node
    
    // Get student details from user
    cout << "Enter name: ";
    cin >> newStudent->name;
    cout << "Enter age: ";
    cin >> newStudent->age;
    cout << "Enter ID: ";
    cin >> newStudent->id;

    newStudent->next = head;  // New student points to current head
    head = newStudent;        // Update head to point to new student
    cout << "Successfully added at beginning.\n";
}

// Inserts a new student at the end of the list
void insertAtEnd() {
    Student* newStudent = new Student;  // Create a new student node
    
    // Get student details from user
    cout << "Enter name: ";
    cin >> newStudent->name;
    cout << "Enter age: ";
    cin >> newStudent->age;
    cout << "Enter ID: ";
    cin >> newStudent->id;
    newStudent->next = NULL;  // New student will be last, so next is NULL

    if (head == NULL) {
        // If list is empty, new student becomes the head
        head = newStudent;
    } else {
        // Otherwise, traverse to the end of the list
        Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;  // Add new student at the end
    }
    cout << "Successfully added at end.\n";
}

// Inserts a new student at a specific position in the list
void insertAtPosition() {
    int pos;  // Position to insert at
    cout << "Position to insert: ";
    cin >> pos;

    if (pos < 1) {
        cout << "Invalid position!\n";
        return;
    }

    // If position is 1, use insertAtBeginning instead
    if (pos == 1) {
        insertAtBeginning();
        return;
    }

    Student* newStudent = new Student;  // Create new student node
    
    // Get student details from user
    cout << "Enter name: ";
    cin >> newStudent->name;
    cout << "Enter age: ";
    cin >> newStudent->age;
    cout << "Enter ID: ";
    cin >> newStudent->id;

    // Traverse to the position before where we want to insert
    Student* temp = head;
    for (int i = 1; i < pos-1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        // If we reached the end before finding the position
        cout << "Position out of range!\n";
        delete newStudent;  // Clean up the unused node
        return;
    }

    // Insert the new student
    newStudent->next = temp->next;
    temp->next = newStudent;
    cout << "Successfully added at position " << pos << ".\n";
}

// Deletes the first student from the list
void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Student* temp = head;  // Store current head
    head = head->next;     // Update head to next student
    cout << "Deleted: " << temp->name << endl;
    delete temp;           // Free memory of deleted student
}

// Deletes the last student from the list
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (head->next == NULL) {
        // If there's only one student in the list
        cout << "Deleted: " << head->name << endl;
        delete head;
        head = NULL;
        return;
    }

    // Traverse to the second-to-last student
    Student* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Delete the last student
    cout << "Deleted: " << temp->next->name << endl;
    delete temp->next;
    temp->next = NULL;  // Set new end of list
}

// Deletes a student from a specific position in the list
void deleteFromPosition() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    int pos;  // Position to delete
    cout << "Position to delete: ";
    cin >> pos;

    if (pos < 1) {
        cout << "Invalid position!\n";
        return;
    }

    // If position is 1, use deleteFromBeginning instead
    if (pos == 1) {
        deleteFromBeginning();
        return;
    }

    // Traverse to the position before the one to delete
    Student* temp = head;
    for (int i = 1; i < pos-1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of range!\n";
        return;
    }

    // Delete the student at the specified position
    Student* toDelete = temp->next;
    temp->next = temp->next->next;
    cout << "Deleted: " << toDelete->name << endl;
    delete toDelete;
}

// Searches for a student by ID and displays their information
void searchForElement() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    int searchId;  // ID to search for
    cout << "Enter ID to search: ";
    cin >> searchId;

    Student* temp = head;  // Start at the head of the list
    int position = 1;      // Track current position
    bool found = false;    // Flag to indicate if student was found

    while (temp != NULL) {
        if (temp->id == searchId) {
            // Display found student's information
            cout << "Student found at position " << position << ":\n";
            cout << "Name: " << temp->name << "\n";
            cout << "Age: " << temp->age << "\n";
            cout << "ID: " << temp->id << "\n";
            found = true;
            break;
        }
        temp = temp->next;
        position++;
    }

    if (!found) {
        cout << "Student with ID " << searchId << " not found.\n";
    }
}

// Displays all students in the list
void displayList() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Student* temp = head;  // Start at the head
    int count = 1;         // Student counter
    
    cout << "\nStudent List:\n";
    while (temp != NULL) {
        // Display each student's information
        cout << "Student " << count++ << ":\n"
             << "Name: " << temp->name << "\n"
             << "Age: " << temp->age << "\n"
             << "ID: " << temp->id << "\n\n";
        temp = temp->next;  // Move to next student
    }
}

// Deletes all students in the list to free memory
void deleteList() {
    while (head != NULL) {
        Student* temp = head;  // Store current head
        head = head->next;     // Move head to next student
        delete temp;           // Delete the stored student
    }
}
