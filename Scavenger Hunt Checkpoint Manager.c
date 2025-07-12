//Scavenger Hunt Checkpoint Manager.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Hunt {
    char clue[30];
    struct Hunt *next;
};

struct Hunt *head = NULL;
struct Hunt *tail = NULL;

// Add clue at the end
void addEnd(char clue[]) {
    struct Hunt *newNode = (struct Hunt *)malloc(sizeof(struct Hunt));
    strcpy(newNode->clue, clue);
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Display all clues
void display() {
    struct Hunt *temp = head;
    int count = 1;

    if (temp == NULL) {
        printf("No checkpoints added yet.\n");
        return;
    }

    while (temp != NULL) {
        printf("Checkpoint %d: %s\n", count, temp->clue);
        count++;
        temp = temp->next;
    }
}

// Find clue at a specific position
void find(int value) {
    struct Hunt *temp = head;
    int i;

    if (temp == NULL) {
        printf("No checkpoints added yet.\n");
        return;
    }

    for (i = 1; i < value && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Checkpoint %d not found.\n",value);
    } else {
        printf("Clue at Checkpoint %d: %s\n", value, temp->clue);
    }
}

// Main function
int main() {
    int n, key, pos;
    char clue[30];

    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        switch (key) {
            case 1:
                scanf("%s", clue);
                addEnd(clue);
                break;
            case 2:
                display();
                break;
            case 3:
                scanf("%d", &pos);
                find(pos);
                break;
            case 4:
                exit(0);
            
        }
    }
    return 0;
}
