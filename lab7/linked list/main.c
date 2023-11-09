#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertBefore(struct Node** head, int element, int newData) {
    struct Node* newNode = createNode(newData);
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->data == element) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL && current->next->data != element) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Element not found in the list.\n");
        free(newNode);
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}
void insertAfter(struct Node* head, int element, int newData) {
    struct Node* newNode = createNode(newData);
    while (head != NULL) {
        if (head->data == element) {
            newNode->next = head->next;
            head->next = newNode;
            return;
        }
        head = head->next;
    }
    printf("Element not found in the list.\n");
    free(newNode);
}
void deleteElement(struct Node** head, int target) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == target) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != target) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found in the list.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}
void traverseList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    *head = prev;
}
void deleteAlternate(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* current = head;
    struct Node* temp;

    while (current != NULL && current->next != NULL) {
        temp = current->next;
        current->next = temp->next;
        free(temp);
        current = current->next;
    }
}
void insertInSorted(struct Node** head, int newData) {
    struct Node* newNode = createNode(newData);
    struct Node* current = *head;
    struct Node* prev = NULL;

    if (*head == NULL || (*head)->data >= newData) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    while (current != NULL && current->data < newData) {
        prev = current;
        current = current->next;
    }

    prev->next = newNode;
    newNode->next = current;
}

int main() {
    struct Node* head = NULL;
    int choice, element, newData;

    while (1) {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert an element before another element\n");
        printf("2. Insert an element after another element\n");
        printf("3. Delete an element\n");
        printf("4. Traverse the list\n");
        printf("5. Reverse the list\n");
        printf("6. Sort the list\n");
        printf("7. Delete every alternate node\n");
        printf("8. Insert an element in sorted order\n");
        printf("9. Display the linked list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element before which you want to insert: ");
                scanf("%d", &element);
                printf("Enter the new data: ");
                scanf("%d", &newData);
                insertBefore(&head, element, newData);
                break;
            case 2:
                printf("Enter the element after which you want to insert: ");
                scanf("%d", &element);
                printf("Enter the new data: ");
                scanf("%d", &newData);
                insertAfter(head, element, newData);
                break;
            case 3:
                printf("Enter the element you want to delete: ");
                scanf("%d", &element);
                deleteElement(&head, element);
                break;
            case 4:
                traverseList(head);
                break;
            case 5:
                reverseList(&head);
                printf("List reversed successfully.\n");
                break;
            case 6:
                printf("Sorting is not implemented in this example.\n");
                break;
            case 7:
                deleteAlternate(head);
                printf("Every alternate node deleted successfully.\n");
                break;
            case 8:
                printf("Enter the data to insert in sorted order: ");
                scanf("%d", &newData);
                insertInSorted(&head, newData);
                break;
            case 9:
                traverseList(head);
                break;
            case 0:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
