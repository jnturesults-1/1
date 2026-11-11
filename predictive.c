
#include <stdio.h>
#include <string.h>

char stack[100];
char input[100];
int top = -1, ip = 0;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

void firstfollow()
{
    printf("First(E) = { (, id }\n");
    printf("First(Q) = { +, e }\n");
    printf("First(T) = { (, id }\n");
    printf("First(R) = { *, e }\n");
    printf("First(F) = { (, id }\n");

    printf("Follow(E) = { ), $ }\n");
    printf("Follow(Q) = { ), $ }\n");
    printf("Follow(T) = { +, ), $ }\n");
    printf("Follow(R) = { +, ), $ }\n");
    printf("Follow(F) = { *, +, ), $ }\n");
}

int col(char ch)
{
    if (ch == 'i' && input[ip + 1] == 'd')
        return 0;

    switch (ch)
    {
    case '+':
        return 1;
    case '*':
        return 2;
    case '(':
        return 3;
    case ')':
        return 4;
    case '$':
        return 5;
    }

    return -1;
}

int row(char ch)
{
    switch (ch)
    {
    case 'E':
        return 0;
    case 'Q':
        return 1;
    case 'T':
        return 2;
    case 'R':
        return 3;
    case 'F':
        return 4;
    }

    return -1;
}

char *table[5][6] =
    {
        {"TQ", "", "", "TQ", "", ""},
        {"", "+TQ", "", "", "#", "#"},
        {"FR", "", "", "FR", "", ""},
        {"", "#", "*FR", "", "#", "#"},
        {"i", "", "", "(E)", "", ""}};

void printtable()
{
    printf("\n\tPREDICTIVE PARSING TABLE\n\n");
    printf("+------+-------+-------+-------+-------+-------+-------+\n");
    printf("| NT/T |  id   |   +   |   *   |   (   |   )   |   $   |\n");
    printf("+------+-------+-------+-------+-------+-------+-------+\n");

    char nonterminals[] = {'E', 'Q', 'T', 'R', 'F'};

    for (int i = 0; i < 5; i++)
    {
        printf("|  %c   ", nonterminals[i]);
        for (int j = 0; j < 6; j++)
        {
            if (table[i][j][0] == '\0')
                printf("|       ");
            else
                printf("| %-5s ", table[i][j]);
        }
        printf("|\n");
        printf("+------+-------+-------+-------+-------+-------+-------+\n");
    }
}

int main()
{
    firstfollow();
    printtable();

    printf("\nEnter input ending with $: ");
    scanf("%99s", input);

    push('$');
    push('E');

    while (!(peek() == '$' && input[ip] == '$'))
    {
        char x = peek();
        char a = input[ip];

        if (x == 'i'){
            if (a == 'i' && input[ip + 1] == 'd'){
                pop();
                ip = ip + 2;
            }else{
                printf("\nInvalid string\n");
                return 0;
            }
        }else if (x == a){
            pop();
            ip++;
        }else if (x >= 'A' && x <= 'Z'){
            int r = row(x);
            int c = col(a);

            if (r == -1 || c == -1 || table[r][c][0] == '\0')
            {
                printf("\nInvalid string\n");
                return 0;
            }

            pop();

            if (table[r][c][0] != '#')
            {
                int len = strlen(table[r][c]);

                for (int j = len - 1; j >= 0; j--)
                    push(table[r][c][j]);
            }
        }else{
            printf("\nInvalid string\n");
            return 0;
        }
    }

    if (input[ip] == '$')
        printf("\nValid string\n");
    else
        printf("\nInvalid string\n");

    return 0;
}
