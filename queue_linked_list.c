#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into queue\n", value);
}

void dequeue() {
    struct Node *temp;

    if(front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;
    printf("Deleted Element: %d\n", front->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

void peek() {
    if(front == NULL)
        printf("Queue is Empty\n");
    else
        printf("Front Element: %d\n", front->data);
}

void display() {
    struct Node *temp = front;

    if(front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue Elements: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice\n");
        }

    } while(choice != 5);

    return 0;
}