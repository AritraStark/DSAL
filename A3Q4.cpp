#include <stdio.h>
#include <iostream>
using namespace std;

int* max(int a,int b){
    return a>b?&a:&b;
}


int main(){
    int a,b,*x,y;
    cout<<"Enter numbers"<<endl;
    cin>>a>>b;
    x=max(a,b);
    y=*max(a,b);
    cout<<"Result is : "<<*x<<" "<<y;
    return 0;
}