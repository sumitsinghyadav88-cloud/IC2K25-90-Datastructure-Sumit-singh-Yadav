
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

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
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

    do {
        if (temp->data == value) {
            break;
        }

        previous = temp;
        temp = temp->next;

    } while (temp != head);

    if (temp->data != value) {
        cout << "Element not found.\n";
        return;
    }

    if (temp == head && temp->next == head) {
        head = NULL;
    } else if (temp == head) {
        Node* last = head;

        while (last->next != head) {
            last = last->next;
        }

        head = head->next;
        last->next = head;
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

    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    do {
        if (temp->data == value) {
            cout << "Element found at position " << position << endl;
            return;
        }

        temp = temp->next;
        position++;

    } while (temp != head);

    cout << "Element not found.\n";
}

void displayList() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "Circular Linked List: ";

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(Back to Head)\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- CIRCULAR LINKED LIST ---\n";
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
