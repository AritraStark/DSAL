#include <stdio.h>
#include <iostream>
//#include<bits/stdc++.h>
using namespace std;

void f(int a,int b){
    cout<<endl<<a<<" "<<b;
}

void f(char a,int b){
    cout<<endl<<a<<" "<<b;
}

int main(){
    int a;
    char b;
    float c;

    cout<<"Enter int char and float"<<endl;
    cin>>a>>b>>c;
    f(a,b);
    f(b,b);
    //f(c,c);
    return 0;
}