#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    int id;
    Student* next;
};

Student* head = NULL;

void displayMenu();
void insertAtBeginning();
void insertAtEnd();
void insertAtPosition();
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromPosition();
void searchForElement();
void displayList();
void deleteList();

int main() {
    displayMenu();
    deleteList();
    return 0;
}

void displayMenu() {
    int choice;
    do {
        cout << "\nCIRCULAR SINGLY LINKED LIST MENU\n"
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
        cin >> choice;

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
    } while (choice != 9);
}

void insertAtBeginning() {
    Student* newStudent = new Student;
    cout << "Enter name: ";
    cin >> newStudent->name;
    cout << "Enter age: ";
    cin >> newStudent->age;
    cout << "Enter ID: ";
    cin >> newStudent->id;

    if (head == NULL) {
        newStudent->next = newStudent; // Points to itself
        head = newStudent;
    } else {
        // Find the last node
        Student* last = head;
        while (last->next != head) {
            last = last->next;
        }
        newStudent->next = head;
        head = newStudent;
        last->next = head; // Update last node's next
    }
    cout << "Successfully added at beginning.\n";
}

void insertAtEnd() {
    Student* newStudent = new Student;
    cout << "Enter name: ";
    cin >> newStudent->name;
    cout << "Enter age: ";
    cin >> newStudent->age;
    cout << "Enter ID: ";
    cin >> newStudent->id;

    if (head == NULL) {
        newStudent->next = newStudent;
        head = newStudent;
    } else {
        Student* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newStudent;
        newStudent->next = head;
    }
    cout << "Successfully added at end.\n";
}

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
    for (int i = 1; i < pos-1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head && pos > 1) {
        // Inserting after last node is same as insertAtEnd
        temp->next = newStudent;
        newStudent->next = head;
    } else {
        newStudent->next = temp->next;
        temp->next = newStudent;
    }
    cout << "Successfully added at position " << pos << ".\n";
}

void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (head->next == head) { // Only one node
        cout << "Deleted: " << head->name << endl;
        delete head;
        head = NULL;
    } else {
        Student* last = head;
        while (last->next != head) {
            last = last->next;
        }
        Student* temp = head;
        head = head->next;
        last->next = head;
        cout << "Deleted: " << temp->name << endl;
        delete temp;
    }
}

void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (head->next == head) { // Only one node
        cout << "Deleted: " << head->name << endl;
        delete head;
        head = NULL;
    } else {
        Student* temp = head;
        Student* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        cout << "Deleted: " << temp->name << endl;
        delete temp;
    }
}

void deleteFromPosition() {
    if (head == NULL) {
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
    Student* prev = NULL;
    for (int i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head || (temp->next == head && pos > 1)) {
        cout << "Position out of range!\n";
        return;
    }

    prev->next = temp->next;
    cout << "Deleted: " << temp->name << endl;
    delete temp;
}

void searchForElement() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    int searchId;
    cout << "Enter ID to search: ";
    cin >> searchId;

    Student* temp = head;
    int position = 1;
    bool found = false;

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
        cout << "Student with ID " << searchId << " not found.\n";
    }
}

void displayList() {
    if (head == NULL) {
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
}

void deleteList() {
    if (head == NULL) return;
    
    Student* current = head;
    Student* nextNode;
    
    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);
    
    head = NULL;
}
