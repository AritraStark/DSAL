#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    a=a+b;
    b=a-b;
    a=a-b;
}

int main(){
    int a,b;
    cout<<"Enter numbers to swap"<<endl;
    cin>>a>>b;
    cout<<"Before swap : "<<a<<" "<<b<<endl;
    swap(a,b);
    cout<<"After swap : "<<a<<" "<<b<<endl;
    return 0;
}