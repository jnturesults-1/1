#include <stdio.h>

static int x = 10;
static int y = 20;

int main()
{
    int z = x+y;
    printf("x= %d",x);
    printf("\ny= %d", y);
    printf("\nz= %d", z);

    return 0;
}