/// add a song in the play list using linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a song node
struct Song {
    char name[100];
    struct Song* next;
};

// Global head pointer
struct Song* head = NULL;

// Function prototypes
void addSong(const char* name);
void displayPlaylist();
void deleteSong(const char* name);
void freePlaylist();

int main() {
    int choice;
    char name[100];

    while (1) {
        printf("\n=== Audio Player Playlist Menu ===\n");
        printf("1. Add Song\n");
        printf("2. Display Playlist\n");
        printf("3. Delete Song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter song name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // remove newline
                addSong(name);
                break;
            case 2:
                displayPlaylist();
                break;
            case 3:
                printf("Enter song name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                deleteSong(name);
                break;
            case 4:
                freePlaylist();
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// Add song to the end of the playlist
void addSong(const char* name) {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong->name, name);
    newSong->next = NULL;

    if (head == NULL) {
        head = newSong;
    } else {
        struct Song* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSong;
    }

    printf("'%s' added to the playlist.\n", name);
}

// Display all songs
void displayPlaylist() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    struct Song* temp = head;
    int index = 1;

    printf("\nPlaylist:\n");
    while (temp != NULL) {
        printf("%d. %s\n", index++, temp->name);
        temp = temp->next;
    }
}

// Delete song by name
void deleteSong(const char* name) {
    struct Song* temp = head;
    struct Song* prev = NULL;

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Song not found.\n");
        return;
    }

    if (temp == head) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("'%s' deleted from the playlist.\n", name);
}

// Free the playlist memory
void freePlaylist() {
    struct Song* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
