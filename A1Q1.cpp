#include <iostream>
using namespace std;

int main()
{
    int a=10;
    int *p;
    int **pp;
    p=&a;
    pp=&p;
    cout<<a<<endl;
    cout<<*p<<endl;
    cout<<**pp<<endl;
    return 0;
}
