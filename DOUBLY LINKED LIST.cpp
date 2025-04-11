#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    int id;
    Student* next;
    Student* prev;
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

int main() {
    displayMenu();
    return 0;
}

void displayMenu() {
    int choice;
    do {
        cout << "\nDOUBLY LINKED LIST MENU\n"
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
            case 9: cout << "Exiting the program.\n"; break;
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

    newStudent->prev = NULL;
    newStudent->next = head;

    if (head != NULL) {
        head->prev = newStudent;
    }

    head = newStudent;
    cout << "Successfully Added at beginning.\n";
}

void insertAtEnd() {
    Student* newStudent = new Student;
    cout << "Enter name: ";
    cin >> newStudent->name;
    cout << "Enter age: ";
    cin >> newStudent->age;
    cout << "Enter ID: ";
    cin >> newStudent->id;

    newStudent->next = NULL;

    if (head == NULL) {
        newStudent->prev = NULL;
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
        newStudent->prev = temp;
    }
    cout << "Added at end.\n";
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
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of range!\n";
        return;
    }

    newStudent->next = temp->next;
    newStudent->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newStudent;
    }
    temp->next = newStudent;
    cout << "Added at position " << pos << ".\n";
}

void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Student* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    cout << "Deleted: " << temp->name << endl;
    delete temp;
}

void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Student* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    cout << "Deleted: " << temp->name << endl;
    delete temp;
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
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of range!\n";
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    temp->prev->next = temp->next;
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
    bool found = false;
    int position = 1;

    while (temp != NULL) {
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
    }

    if (!found) {
        cout << "Student with ID " << searchId << " not found in the list.\n";
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
    while (temp != NULL) {
        cout << "Student " << count++ << ":\n"
             << "Name: " << temp->name << "\n"
             << "Age: " << temp->age << "\n"
             << "ID: " << temp->id << "\n\n";
        temp = temp->next;
    }
    cout << "End of student list.\n";
}
