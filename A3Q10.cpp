#include <stdio.h>
#include <iostream>

using namespace std;

class STACK{
    private:
    int top=0;
    int arr[100];

    public:
    void push(){
        int data;
        cout<<"Enter data to push"<<endl;
        cin>>data;
        arr[++top]=data;
    }
    void pop(){
        if(top<=-1)
        cout<<"Stack Underflow"<<endl;
        else {
        cout<<"The popped element is "<< arr[top] <<endl;
        top--;
   }
    }
    void show(){
        cout<<"The stack is :"<<endl;
        for(int i=top;i>0;i--)
        cout<<arr[i]<<endl;
    }

};

int main(){
    STACK s1;

    for(;;){
        cout<<"\nEnter \n 1. Push \n 2. Pop \n 3. Show \n 4. Exit"<<endl;
    int a;
    cin>>a;
    switch (a)
    {
        case 1:{
            s1.push();
            break;
        }
        case 2:{
            s1.pop();
            break;
        }
        case 3:{
            s1.show();
            break;
        }
        case 4:{
            exit(0);
            break;
        }
        default:{
            cout<<"Wrong Entry"<<endl;
            break;
        }
        
    }
    }
    
    

    return 0;
}