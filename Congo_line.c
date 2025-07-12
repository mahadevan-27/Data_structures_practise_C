//Congoline (using swutch case)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
	char name[30];
	struct Node *prev;
	struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void addend(char name[]) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	strcpy(newNode->name, name);
	newNode->next = NULL;
	newNode->prev = NULL;

	if (head == NULL && tail == NULL) {
		// First node in the list
		head = tail = newNode;
	} else {
		// Append at the end
		head->next = newNode;
		newNode->prev = head;
		head = newNode;
	}
}

void display() {
	struct Node *temp = tail;
	if (temp == NULL) {
		printf("Congo line is empty.\n");
		return;
	}

	printf("Congo Line:");
	while (temp != NULL) {
		printf(" %s", temp->name);
		temp = temp->next;
	}
	printf("\n");
}

void removename() {
	if (tail == NULL) {
		printf("Congo line is empty. No one to remove.\n");
		return;
	}

	struct Node *temp = tail;
	printf("%s has left the Congo line.\n", temp->name);

	if (tail == head) {
		// Only one node
		head = tail = NULL;
	} else {
		tail = tail->next;
		tail->prev = NULL;
	}

	free(temp);
}

int main() {
	int n, i, key;
	char name[30];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &key);
		getchar();  // clear newline from buffer

		switch (key) {
		case 1:
			scanf("%s", name);
			addend(name);
			break;

		case 2:
			removename();
			break;

		case 3:
			display();
			break;

		case 4:
			exit(0);

		default:
			printf("Invalid option\n");
		}
	}

	return 0;
}
