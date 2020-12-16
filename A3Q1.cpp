#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX(x,y) ((x>y)?x:y)

void integr(){
    int a,b,c;
    cout<<"Enter numbers to compare\n";
    cin>>a>>b;
    c= MAX(a,b);
    cout<<endl<<"The result is "<<c<<endl;
}

void chr(){
    char *a,*b;
    int c;
    cout<<"Enter numbers to compare\n";
    cin>>*a>>*b;
    c= MAX(*a,*b);
    cout<<endl<<"The result is \n"<<c<<endl;
}

int main(){

    for(;;){
        cout<<"Enter : \n1 For integer argument\n2. For character argument\n3.To exit\n";
        int c;
        cin>>c;
        switch(c){
            case 1:{
                integr();
                break;
            }
            case 2:{
                chr();
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