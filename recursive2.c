#include <stdio.h>

char ip[100];
int pos = 0, error = 0;

void S();
void L();
void Lprime();
void S()
{
    if (ip[pos] == '('){
        pos++;
        L();
        if (ip[pos] == ')')
            pos++;
        else
            error = 1;
    }else if (ip[pos] == 'a'){
        pos++;
    }else{
        error = 1;
    }
}

void L()
{
    S();
    Lprime();
}

void Lprime()
{
    if (ip[pos] == ','){
        pos++;
        S();
        Lprime();
    }
}

int main()
{
    printf("Enter string: ");
    scanf("%99s", ip);
    S();
    if (ip[pos] = '\0' && error == 0)
        printf("String is accepted\n");
    else
        printf("String is not accepted\n");
    return 0;
}