#include <stdio.h>
#include <conio.h>

void main()
{
    int a=15;
    int *p;
    int **pp;
    p=&a;
    pp=&p;
    printf("%d\n",a);
    printf("%d\n",*p);
    printf("%d\n",**pp);
}
