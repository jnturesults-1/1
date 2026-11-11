#include <stdio.h>
int action[6][3] = {
    {3, -3, -3},
    {0, 0, 999},
    {0, 5, -5},
    {0, -2, -2},
    {0, 0, -1},
    {0, 0, -4}};

int go[6][3] = {
    {1, 2, -1},
    {-1, -1, -1},
    {-1, -1, 4},
    {-1, -1, -1},
    {-1, -1, -1},
    {-1, -1, -1}};

char lhs[] = {' ', 'S', 'A', 'A', 'B', 'B'};
int len[] = {0, 2, 1, 0, 1, 0};
char *p[] = {"", "AB", "a", "e", "b", "e"};

int main()
{
    char s[100], stack[100];
    int st[100], top = -1, i = 0,c;
    printf("Enter input string (a, b): ");
    scanf("%99s", s);

    stack[++top] = '$';
    st[top] = 0;
    while (1){
        char ch = s[i];
        switch (ch){
            case 'a':
                c = 0;
                break;
            case 'b':
                c = 1;
                break;
            case '$':
                c = 2;
                break;
            default:
                printf("Invalid input\n");
                return 0;
        }
        int x = action[st[top]][c];
        if (x == 999)
        {
            printf("String Accepted\n");
            break;
        }
        if (x > 0)
        {
            printf("Shift %d\n", x);
            stack[++top] = s[i];
            st[top] = x;
            i++;
        }else if (x < 0){
            int r = -x;
            printf("Reduce %c -> %s\n", lhs[r], p[r]);
            top -= len[r];
            int k = lhs[r] == 'S' ? 0 : lhs[r]=='A'?1:2;
            int next = go[st[top]][k];
            if (next == -1){
                printf("String Rejected\n");
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