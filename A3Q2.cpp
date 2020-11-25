#include<bits/stdc++.h>
using namespace std;


inline double multiply(double a, double b){
    return a*b;
}

int main(){
    double a,b,c;
    cout<<"Enter numbers to multiply"<<endl;
    cin>>a>>b;
    c=multiply(a,b);
    cout<<"Result is  : "<<c;
    return 0;
}