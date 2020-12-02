#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class NODE{
    public:
    int data;
    NODE *link;

};

class LIST{
    NODE *head = NULL;

    public:
    void add(){
        NODE temp;
        cout<<"Enter new data:"<<endl;
        cin>>temp.data;
        if(head==NULL)
        *head = temp;
        else{
            temp.link=head;
            *head=temp;
        }
    }
};

int main(){

    return 0;
}