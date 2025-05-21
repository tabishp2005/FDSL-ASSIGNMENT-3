#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[100];
    struct Node* next;
};

struct Node* head = NULL;

// Insert at beginning
void insertFirst() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter string: ");
    scanf("%s", newNode->data);
    newNode->next = head;
    head = newNode;
    printf("Inserted at beginning.\n");
}

// Insert at end
void insertLast() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter string: ");
    scanf("%s", newNode->data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted at end.\n");
}

// Insert at position (1-based index)
void insertAtPosition(int pos) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        insertFirst();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position out of range.\n");
            return;
        }
        temp = temp->next;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter string: ");
    scanf("%s", newNode->data);

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted at position %d.\n", pos);
}

// Insert after position
void insertAfterPosition(int pos) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos; i++) {
        if (temp == NULL) {
            printf("Position out of range.\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter string: ");
    scanf("%s", newNode->data);

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted after position %d.\n", pos);
}

// Delete first
void deleteFirst() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    printf("Deleted: %s\n", temp->data);
    free(temp);
}

// Delete last
void deleteLast() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted: %s\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    printf("Deleted: %s\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// Delete at position
void deleteAtPosition(int pos) {
    if (pos < 1 || head == NULL) {
        printf("Invalid operation.\n");
        return;
    }

    if (pos == 1) {
        deleteFirst();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Position out of range.\n");
            return;
        }
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    printf("Deleted: %s\n", delNode->data);
    free(delNode);
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List:\n");
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main menu
int main() {
    int choice, pos;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Insert at First\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Insert After Position\n");
        printf("5. Delete at First\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Position\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertFirst();
                break;
            case 2:
                insertLast();
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(pos);
                break;
            case 4:
                printf("Enter position after which to insert: ");
                scanf("%d", &pos);
                insertAfterPosition(pos);
                break;
            case 5:
                deleteFirst();
                break;
            case 6:
                deleteLast();
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 8:
                display();
                break;
            case 9:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 9);

    return 0;
}