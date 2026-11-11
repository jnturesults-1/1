#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *stack = NULL;
    int top = -1;
    int choice, value;
    int *temp;
    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("Enter the element: ");
            scanf("%d", &value);
            temp = realloc(stack,(top + 2) * sizeof(int));
            stack = temp;
            stack[++top] = value;
            printf("%d pushed into the stack.\n", value);
            break;
        case 2:
            if (top == -1){
                printf("Stack is empty!\n");
            }else{
                printf("Popped element: %d\n", stack[top]);
                top--;
                if (top == -1){
                    free(stack);
                    stack = NULL;
                }else{
                    temp = realloc(stack,(top + 1) * sizeof(int));
                    if (temp != NULL) stack = temp;
                }
            }
            break;
        case 3:
            if (top == -1){
                printf("Stack is empty!\n");
            }else{
                printf("Stack elements are:\n");
                for (int i = top; i >= 0; i--){
                    printf("%d\n", stack[i]);
                }
            }
            break;
        case 4:
            free(stack);
            printf("Memory released. Exiting...\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}