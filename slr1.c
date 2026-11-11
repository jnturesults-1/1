
#include <stdio.h>

int a[12][6] = {
    {5, 0, 0, 4, 0, 0},
    {0, 6, 0, 0, 0, 999},
    {0, -2, 7, 0, -2, -2},
    {0, -4, -4, 0, -4, -4},
    {5, 0, 0, 4, 0, 0},
    {0, -6, -6, 0, -6, -6},
    {5, 0, 0, 4, 0, 0},
    {5, 0, 0, 4, 0, 0},
    {0, 6, 0, 0, 11, 0},
    {0, -1, 7, 0, -1, -1},
    {0, -3, -3, 0, -3, -3},
    {0, -5, -5, 0, -5, -5}
};

int g[12][3] = {
    {1, 2, 3},
    {-1, -1, -1},
    {-1, -1, -1},
    {-1, -1, -1},
    {8, 2, 3},
    {-1, -1, -1},
    {-1, 9, 3},
    {-1, -1, 10},
    {-1, -1, -1},
    {-1, -1, -1},
    {-1, -1, -1},
    {-1, -1, -1}
};

char *p[] = {"", "E+T", "T", "T*F", "F", "(E)", "id"};
char lhs[] = {' ', 'E', 'E', 'T', 'T', 'F', 'F'};
int len[] = {0, 3, 1, 3, 1, 3, 1};

int main()
{
    char s[100], stack[100];
    int st[100], top = -1, i = 0, c;

    printf("Enter string ending with $: ");
    scanf("%98s", s);

    stack[++top] = '$';
    st[top] = 0;

    while (1)
    {
        char ch = s[i];
        switch (ch){
        case 'i':
            if (s[i + 1] == 'd'){
                c = 0;
            }else{
                printf("Invalid input\n");
                return 0;
            }
            break;

        case '+':
            c = 1;
            break;

        case '*':
            c = 2;
            break;

        case '(':
            c = 3;
            break;

        case ')':
            c = 4;
            break;

        case '$':
            c = 5;
            break;

        default:
            printf("Invalid input\n");
            return 0;
        }

        int x = a[st[top]][c];
        if (x == 999){
            printf("String Accepted\n");
            break;
        }else if (x > 0){
            printf("Shift %d\n", x);
            
            stack[++top] = ch;
            st[top] = x;

            if (ch == 'i')
                i = i + 2;
            else
                i++;
        }else if (x < 0){
            int r = -x;

            printf("Reduce %c -> %s\n", lhs[r], p[r]);

            top -= len[r];

            int k = lhs[r] == 'E' ? 0 : lhs[r] == 'T' ? 1: 2;

            int next = g[st[top]][k];

            if (next == -1)
            {
                printf("Rejected\n");
                break;
            }

            stack[++top] = lhs[r];
            st[top] = next;
        }else{
            printf("String Rejected\n");
            break;
        }

        printf("Stack: ");

        for (int j = 0; j <= top; j++)
            printf("%c%d ", stack[j], st[j]);

        printf("\n");
    }

    return 0;
}
