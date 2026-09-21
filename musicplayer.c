#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char song[50];
    struct Node *next;
};

struct Node *head = NULL;


void addSong() {
    struct Node *newNode, *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter song name: ");
    scanf(" %[^\n]s", newNode->song); // Reads string with spaces
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Song added successfully!\n");
}


void removeSong() {
    if (head == NULL) {
        printf("Playlist is empty!\n");
        return;
    }

    char name[50];
    printf("Enter song name to remove: ");
    scanf(" %[^\n]s", name);

    struct Node *temp = head, *prev = NULL;

    if (strcmp(temp->song, name) == 0) {
        head = temp->next;
        free(temp);
        printf("Song removed successfully!\n");
        return;
    }

    while (temp != NULL && strcmp(temp->song, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Song not found in playlist!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Song removed successfully!\n");
}


void moveUp() {
    if (head == NULL || head->next == NULL) {
        printf("Not enough songs to move!\n");
        return;
    }

    char name[50];
    printf("Enter song name to move up: ");
    scanf(" %[^\n]s", name);

    if (strcmp(head->song, name) == 0) {
        printf("Song is already at the top of the playlist!\n");
        return;
    }

    struct Node *prev2 = NULL, *prev1 = head, *curr = head->next;

    while (curr != NULL && strcmp(curr->song, name) != 0) {
        prev2 = prev1;
        prev1 = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Song not found!\n");
        return;
    }


    prev1->next = curr->next;
    curr->next = prev1;

    if (prev2 == NULL) {
        head = curr;
    } else {
        prev2->next = curr;
    }
    printf("Song moved up successfully!\n");
}

// Function to move a song down in the playlist
void moveDown() {
    if (head == NULL || head->next == NULL) {
        printf("Not enough songs to move!\n");
        return;
    }

    char name[50];
    printf("Enter song name to move down: ");
    scanf(" %[^\n]s", name);

    struct Node *prev = NULL, *curr = head, *nextNode = head->next;

    while (curr != NULL && strcmp(curr->song, name) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL || curr->next == NULL) {
        printf("Song cannot be moved down (already at the bottom or not found)!\n");
        return;
    }

    nextNode = curr->next;
    curr->next = nextNode->next;
    nextNode->next = curr;

    if (prev == NULL) {
        head = nextNode;
    } else {
        prev->next = nextNode;
    }
    printf("Song moved down successfully!\n");
}

// Function to display all songs in the playlist
void displayPlaylist() {
    if (head == NULL) {
        printf("\n--- Playlist is empty ---\n");
        return;
    }

    struct Node *temp = head;
    int count = 1;
    printf("\n--- Current Playlist ---\n");
    while (temp != NULL) {
        printf("%d. %s\n", count++, temp->song);
        temp = temp->next;
    }
    printf("------------------------\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n*** Music Playlist Menu ***\n");
        printf("1. Add Song\n");
        printf("2. Remove Song\n");
        printf("3. Move Song Up\n");
        printf("4. Move Song Down\n");
        printf("5. Display Playlist\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addSong(); break;
            case 2: removeSong(); break;
            case 3: moveUp(); break;
            case 4: moveDown(); break;
            case 5: displayPlaylist(); break;
            case 6: 
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
