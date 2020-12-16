#include <iostream>
using namespace std;

double calc(double i,double t=0.1){
    return (t*i);
}

int main(){
    double i,t;
    cout<<"Enter income and tax rate";
    cin>>i>>t;
    t/=100;
    double res= calc(i,t);
    double res2=calc(i);
    cout<<"Results are : "<<res<<" "<<res2;
    return 0;
}