
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertNode() {
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Node inserted successfully.\n";
}

void deleteNode() {
    int value;
    cout << "Enter value to delete: ";
    cin >> value;

    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    Node* previous = NULL;

    while (temp != NULL && temp->data != value) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Element not found.\n";
        return;
    }

    if (previous == NULL) {
        head = head->next;
    } else {
        previous->next = temp->next;
    }

    delete temp;
    cout << "Node deleted successfully.\n";
}

void searchNode() {
    int value, position = 1;
    cout << "Enter value to search: ";
    cin >> value;

    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Element found at position " << position << endl;
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Element not found.\n";
}

void displayList() {
    Node* temp = head;

    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    cout << "Singly Linked List: ";

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- SINGLY LINKED LIST ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertNode();
                break;

            case 2:
                deleteNode();
                break;

            case 3:
                searchNode();
                break;

            case 4:
                displayList();
                break;

            case 5:
                cout << "Program exited.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
