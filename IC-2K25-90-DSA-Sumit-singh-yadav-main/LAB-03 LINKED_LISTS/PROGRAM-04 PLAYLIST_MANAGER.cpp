
#include <iostream>
#include <string>
using namespace std;

struct Song {
    string name;
    Song* next;
    Song* prev;
};

Song* head = NULL;
Song* current = NULL;
int totalSongs = 0;

// Add Song
void addSong() {
    string name;

    cout << "Enter song name: ";
    getline(cin >> ws, name);

    Song* newSong = new Song;
    newSong->name = name;

    if (head == NULL) {
        head = newSong;
        newSong->next = head;
        newSong->prev = head;
        current = head;
    } else {
        Song* last = head->prev;

        last->next = newSong;
        newSong->prev = last;

        newSong->next = head;
        head->prev = newSong;
    }

    totalSongs++;

    cout << "Song added successfully!\n";
}

// Remove Song
void removeSong() {
    if (head == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    string name;
    cout << "Enter song name to remove: ";
    getline(cin >> ws, name);

    Song* temp = head;

    do {
        if (temp->name == name) {
            break;
        }

        temp = temp->next;

    } while (temp != head);

    if (temp->name != name) {
        cout << "Song not found.\n";
        return;
    }

    if (totalSongs == 1) {
        delete temp;
        head = NULL;
        current = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        if (temp == head) {
            head = temp->next;
        }

        if (temp == current) {
            current = temp->next;
        }

        delete temp;
    }

    totalSongs--;

    cout << "Song removed successfully!\n";
}

// Play Current Song
void playCurrentSong() {
    if (current == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    cout << "\nNow Playing: " << current->name << endl;
}

// Play Next Song
void nextSong() {
    if (current == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    current = current->next;

    cout << "Next Song: " << current->name << endl;
}

// Play Previous Song
void previousSong() {
    if (current == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    current = current->prev;

    cout << "Previous Song: " << current->name << endl;
}

// Display Playlist
void displayPlaylist() {
    if (head == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    Song* temp = head;

    cout << "\n------ YOUR PLAYLIST ------\n";

    do {
        if (temp == current) {
            cout << ">> ";
        } else {
            cout << "   ";
        }

        cout << temp->name << endl;

        temp = temp->next;

    } while (temp != head);

    cout << "---------------------------\n";
}

// Main Function
int main() {
    int choice;

    do {
        cout << "\n================================\n";
        cout << "       PLAYLIST MANAGER\n";
        cout << "================================\n";
        cout << "1. Add Song\n";
        cout << "2. Remove Song\n";
        cout << "3. Play Current Song\n";
        cout << "4. Next Song\n";
        cout << "5. Previous Song\n";
        cout << "6. Display Playlist\n";
        cout << "7. Total Songs\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addSong();
                break;

            case 2:
                removeSong();
                break;

            case 3:
                playCurrentSong();
                break;

            case 4:
                nextSong();
                break;

            case 5:
                previousSong();
                break;

            case 6:
                displayPlaylist();
                break;

            case 7:
                cout << "Total Songs: " << totalSongs << endl;
                break;

            case 8:
                cout << "Exiting Playlist Manager...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 8);

    return 0;
}
