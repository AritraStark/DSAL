#include<iostream>
#include<string>
using namespace std;


class Data{
    public:
    int d1,d3;
    char d2;
    Data* next;
    // Data(){
    //     d1=0;
    //     d2='\0';
    // }
};

class DataList{
    private:
    Data *head;
    public:
    DataList(){
        head = NULL;
    }
    void push(int x,char c,int z){
        Data *temp = new Data;
        temp->d1 = x;
        temp->d3 = z;
        temp->d2 = c;
        temp->next = NULL;
        if(head==NULL)
        head = temp;
        else{
            Data* temp1;
            temp1 = head;
            while(temp1->next!=NULL)
            temp1=temp1->next;
            temp1->next = temp;
        }
    }
    void show(){
        Data* temp;
        temp = head;
        while(temp!=NULL){
            cout<<temp->d1<<" "<<temp->d3<<" "<<temp->d2<<" -> ";
            temp=temp->next;
        }
        //cout<<temp->d1<<" "<<temp->d3<<" "<<temp->d2<<" -> ";
    }
    int getter(){
        Data* temp;
        temp = head;
        while(temp!=NULL){
            if(temp->d1==1)
            cout<<temp->d2<<" ";
            cout<<endl;
            temp=temp->next;
        }
    }
};

int main(){
    DataList d1;
    d1.push(1,'c',4);
    d1.push(2,'a',5);
    d1.show();
    d1.getter();
    return 0;
}