#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class APPLICANT{
    int id,score;
    string name;
    
    public:
    APPLICANT(){
        name = "";
        score = 0;
        id = 0;
    }

    APPLICANT(string nm,int sc,int ids){
        name = nm;
        score = sc;
        id = ids;
    }

    int getId(){
        return id+1;
    }

    void show(){
        cout<<"\nId of Applicant: "<<id<<endl;
        cout<<"Name of Applicant: "<<name<<endl;
        cout<<"Score of Applicant: "<<score<<endl;
    }
};

class APPSTK{
    private:
    int top=0;
    APPLICANT arr[100];

    public:
    void push(){
        int ida,scr;
        string nam;
        cout<<"Enter name, score, id( enter 0 for default id ) of applicant "<<endl;
        cin>>nam>>scr>>ida;
        ++top;
        if(ida==0){
            if(top==1)
            arr[top]= APPLICANT(nam,scr,1);
            else
            //arr[top]= APPLICANT(nam,scr,(arr[top-1].getId()));
            cout<<arr[top-1].getId();
        }
        else
        arr[top]= APPLICANT(nam,scr,ida);

    }

    void show(){
        cout<<"The applicant list is :"<<endl;
        for(int i=1;i<=top;i++)
        arr[i].show();
    }

    void find(){
        cout<<"The number of applicants are "<<top<<endl;
    }

};

int main(){
    APPSTK s1;

    for(;;){
        cout<<"\nEnter \n 1. Enter new applicant \n 2. Find number of applicants \n 3. Show all applicants \n 4. Exit"<<endl;
    int a;
    cin>>a;
    switch (a)
    {
        case 1:{
            s1.push();
            break;
        }
        case 2:{
            s1.find();
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