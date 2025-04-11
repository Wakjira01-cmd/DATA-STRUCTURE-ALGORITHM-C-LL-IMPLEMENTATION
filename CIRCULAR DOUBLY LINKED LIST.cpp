#include <iostream>
#include <string>
using namespace std;

// Define the structure for a student node in a circular doubly linked list
struct Student {
    string name;    // Student's name
    int age;        // Student's age
    int id;         // Student's ID (used for searching)
    Student* next;  // Pointer to the next student in the list
    Student* prev;  // Pointer to the previous student in the list
};

// Global head pointer initialized to NULL
Student* head = NULL;

// Function prototypes
void displayMenu();
void insertAtBeginning();
void insertAtEnd();
void insertAtPosition();
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromPosition();
void searchForElement();
void displayList();

int main() {
    displayMenu(); // Start the program
    return 0;
}

// Function to display the main menu and handle user choices
void displayMenu() {
    int choice;
    do {
        cout << "\nCIRCULAR DOUBLY LINKED LIST MENU\n"
            << "1. Insert at beginning\n"
            << "2. Insert at end\n"
            << "3. Insert at position\n"
            << "4. Delete from beginning\n"
            << "5. Delete from end\n"
            << "6. Delete from position\n"
            << "7. Search for element\n"
            << "8. Display list\n"
            << "9. Exit\n"
            << "----------------------\nYour Choice: ";
        cin >> choice; // Get user's choice

        // Process user's choice
        switch (choice) {
        case 1:
            insertAtBeginning();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPosition();
            break;
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            deleteFromPosition();
            break;
        case 7:
            searchForElement();
            break;
        case 8:
            displayList();
            break;
        case 9:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid option! Please try again.\n";
        }
    } while (choice != 9); // Repeat until the user chooses to exit
}

// Function to insert a student at the beginning of the list
void insertAtBeginning() {
    Student* newStudent = new Student;
    cout << "Enter name: ";
    cin >> newStudent->name;
    cout << "Enter age: ";
    cin >> newStudent->age;
    cout << "Enter ID: ";
    cin >> newStudent->id;

    if (!head) {
        newStudent->next = newStudent;
        newStudent->prev = newStudent;
        head = newStudent;
    }
    else {
        Student* last = head->prev;
        newStudent->next = head;
        newStudent->prev = last;
        last->next = newStudent;
        head->prev = newStudent;
        head = newStudent;
    }
    cout << "Successfully Added at beginning.\n";
}

// Function to insert a student at the end of the list
void insertAtEnd() {
    Student* newStudent = new Student;
    cout << "Enter name: ";
    cin >> newStudent->name;
    cout << "Enter age: ";
    cin >> newStudent->age;
    cout << "Enter ID: ";
    cin >> newStudent->id;

    if (!head) {
        newStudent->next = newStudent;
        newStudent->prev = newStudent;
        head = newStudent;
    }
    else {
        Student* last = head->prev;
        newStudent->next = head;
        newStudent->prev = last;
        last->next = newStudent;
        head->prev = newStudent;
    }
    cout << "Added at end.\n";
}

// Function to insert a student at a specific position
void insertAtPosition() {
    int pos;
    cout << "Position to insert: ";
    cin >> pos;

    if (pos < 1) {
        cout << "Invalid position!\n";
        return;
    }

    if (pos == 1) {
        insertAtBeginning();
        return;
    }

    Student* newStudent = new Student;
    cout << "Enter name: ";
    cin >> newStudent->name;
    cout << "Enter age: ";
    cin >> newStudent->age;
    cout << "Enter ID: ";
    cin >> newStudent->id;

    Student* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head && pos > 1) {
        cout << "Position out of range! Inserting at end instead.\n";
        insertAtEnd();
        return;
    }

    newStudent->next = temp->next;
    newStudent->prev = temp;
    temp->next->prev = newStudent;
    temp->next = newStudent;
    cout << "Added at position " << pos << ".\n";
}

// Function to delete a student from the beginning of the list
void deleteFromBeginning() {
    if (!head) {
        cout << "List is empty!\n";
        return;
    }

    Student* temp = head;
    if (temp->next == head) {
        head = NULL;
    }
    else {
        Student* last = head->prev;
        head = head->next;
        last->next = head;
        head->prev = last;
    }
    cout << "Deleted: " << temp->name << endl;
    delete temp;
}

// Function to delete a student from the end of the list
void deleteFromEnd() {
    if (!head) {
        cout << "List is empty!\n";
        return;
    }

    Student* last = head->prev;
    if (last == head) {
        cout << "Deleted: " << head->name << endl;
        delete head;
        head = NULL;
        return;
    }

    cout << "Deleted: " << last->name << endl;
    last->prev->next = head;
    head->prev = last->prev;
    delete last;
}

// Function to delete a student from a specific position
void deleteFromPosition() {
    if (!head) {
        cout << "List is empty!\n";
        return;
    }

    int pos;
    cout << "Position to delete: ";
    cin >> pos;

    if (pos < 1) {
        cout << "Invalid position!\n";
        return;
    }

    if (pos == 1) {
        deleteFromBeginning();
        return;
    }

    Student* temp = head;
    for (int i = 1; i < pos && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head && pos > 1) {
        cout << "Position out of range!\n";
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    cout << "Deleted: " << temp->name << endl;
    delete temp;
}

// Function to search for an element by ID
void searchForElement() {
    if (!head) {
        cout << "List is empty!\n";
        return;
    }

    int searchId;
    cout << "Enter ID to search: ";
    cin >> searchId;

    Student* temp = head;
    bool found = false;
    int position = 1;

    do {
        if (temp->id == searchId) {
            cout << "Student found at position " << position << ":\n";
            cout << "Name: " << temp->name << "\n";
            cout << "Age: " << temp->age << "\n";
            cout << "ID: " << temp->id << "\n";
            found = true;
            break;
        }
        temp = temp->next;
        position++;
    } while (temp != head);

    if (!found) {
        cout << "Student with ID " << searchId << " not found in the list.\n";
    }
}

// Function to display all students in the list
void displayList() {
    if (!head) {
        cout << "List is empty!\n";
        return;
    }

    Student* temp = head;
    int count = 1;
    cout << "\nStudent List:\n";
    do {
        cout << "Student " << count++ << ":\n"
            << "Name: " << temp->name << "\n"
            << "Age: " << temp->age << "\n"
            << "ID: " << temp->id << "\n\n";
        temp = temp->next;
    } while (temp != head);
    cout << "End of student list.\n";
}
