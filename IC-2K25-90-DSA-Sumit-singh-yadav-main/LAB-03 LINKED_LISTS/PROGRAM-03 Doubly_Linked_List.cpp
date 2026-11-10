
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertNode() {
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    cout << "Node inserted successfully.\n";
}

void deleteNode() {
    int value;
    cout << "Enter value to delete: ";
    cin >> value;

    Node* temp = head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Element not found.\n";
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
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

void displayForward() {
    Node* temp = head;

    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    cout << "Forward: NULL <-> ";

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

void displayBackward() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Backward: NULL <-> ";

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }

    cout << "NULL\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- DOUBLY LINKED LIST ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display Forward\n";
        cout << "5. Display Backward\n";
        cout << "6. Exit\n";
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
                displayForward();
                break;

            case 5:
                displayBackward();
                break;

            case 6:
                cout << "Program exited.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
