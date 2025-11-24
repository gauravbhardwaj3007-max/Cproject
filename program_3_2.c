#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int pos, value, i;

    // Creating a simple list of 5 nodes
    for(i=1; i<=5; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i * 10;
        newNode->next = head;
        head = newNode;
    }

    printf("Enter position to insert: ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    temp = head;

    for(i=1; i<pos-1 && temp!=NULL; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    temp = head;
    printf("\nUpdated Linked List: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}


