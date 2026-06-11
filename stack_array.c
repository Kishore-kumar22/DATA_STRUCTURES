#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = value;
    printf("%d pushed into stack\n", value);
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    printf("Deleted Element: %d\n", stack[top--]);
}

void peek() {
    if(top == -1)
        printf("Stack is Empty\n");
    else
        printf("Top Element: %d\n", stack[top]);
}

void display() {
    if(top == -1) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack Elements: ");
    for(int i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
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