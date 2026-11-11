#include <stdio.h>

char ip[100];
int pos = 0;
int error = 0;

void E();
void Eprime();
void T();
void Tprime();
void F();

void E()
{
    T();
    Eprime();
}

void Eprime()
{
    if (ip[pos] == '+')
    {
        pos++;
        T();
        Eprime();
    }
}

void T()
{
    F();
    Tprime();
}

void Tprime()
{
    if (ip[pos] == '*')
    {
        pos++;
        F();
        Tprime();
    }
}

void F()
{
    if (ip[pos] == '(')
    {
        pos++;
        E();

        if (ip[pos] == ')')
            pos++;
        else
            error = 1;
    }else if (ip[pos] == 'i' && ip[pos + 1] == 'd'){
        pos = pos + 2;
    }else{
        error = 1;
    }
}

int main()
{
    printf("Enter a string: ");
    scanf("%99s", ip);

    E();

    if (ip[pos] == '\0' && error == 0)
        printf("String accepted\n");
    else
        printf("Syntax error and string not accepted!\n");

    return 0;
}
