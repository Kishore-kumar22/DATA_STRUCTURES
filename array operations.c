#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX], n, i, pos, element, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("Enter position and element: ");
            scanf("%d%d", &pos, &element);

            for(i = n; i >= pos; i--)
                arr[i] = arr[i - 1];

            arr[pos - 1] = element;
            n++;

            printf("Element inserted.\n");
            break;

        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &pos);

            for(i = pos - 1; i < n - 1; i++)
                arr[i] = arr[i + 1];

            n--;

            printf("Element deleted.\n");
            break;

        case 3:
            printf("Array Elements: ");
            for(i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice\n");
        }

    } while(choice != 4);

    return 0;
}