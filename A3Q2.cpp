#include <stdio.h>
#include <iostream>
using namespace std;


inline double multiply(double a, double b){
    return a*b;
}

 double multi(double a, double b){
    return a*b;
}

int main(){
    for(;;){
        cout<<"Enter : \n1 For normal function\n2. For inline function\n3.To exit\n";
        int c;
        cin>>c;
        switch(c){
            case 1:{
                double a,b,c;
                cout<<"Enter numbers to multiply"<<endl;
                cin>>a>>b;
                c=multi(a,b);
                cout<<"Result is  : "<<c;
                break;
            }
            case 2:{
                double a,b,c;
                cout<<"Enter numbers to multiply"<<endl;
                cin>>a>>b;
                c=multiply(a,b);
                cout<<"Result is  : "<<c;
                break;
            }
            case 3:{
                cout<<"Exiting ...\n";
                exit(0);
            }
            default:{
                cout<<"Wrong input";
                break;
            }
        }
    }
    
    return 0;
}