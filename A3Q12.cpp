#include <iostream>
#include <string>

using namespace std;

class STUDENT{
    int roll, marks[5];
    string name,course,date;
    
    public:
    STUDENT(){
        name = "";
        date = "";
        course="";
        roll = 0;
    }

    void admission(){
      
        cout<<"Enter Name, Roll Number, Course and Date (in DD/MM/YY format)  "<<endl;
        cin>>name>>roll>>course>>date;
    }

    void marksinit(){
        cout<<"Enter Marks for subjects"<<endl;
        for(int i=0;i<5;i++){
            cout<<"Subject "<<i+1<<" :  ";
            cin>>marks[i];
        }
    }

    void marksheet(){
        cout<<"\nRoll Number of Student: "<<roll<<endl;
        cout<<"Name of Student: "<<name<<endl;
        cout<<"Date of Admission: "<<date<<endl;
        cout<<"Enrolled Course: "<<course<<endl;
        cout<<"Marks obtained: "<<endl;
        for(int i=0;i<5;i++)
        cout<<"Subject "<<i+1<<" : "<<marks[i]<<endl;
    }
};



int main(){
    int top=-1;
    STUDENT s1[100];

    for(;;){
        cout<<"\nEnter \n 1. Start a new admission \n 2. Enter marks of the student \n 3. Show the marksheet of current student\n 4. Show the marksheet of all students and total number of students  \n 5. Exit"<<endl;
    int a;
    cin>>a;
    switch (a)
    {
        case 1:{
            s1[++top].admission();
            break;
        }
        case 2:{
            if(top>-1)
            s1[top].marksinit();
            else
            cout<<"No students are present";
            break;
        }
        case 3:{
            if(top>-1)
            s1[top].marksheet();
            else
            cout<<"No students are present";
            break;
        }
        case 4:{
            if(top>-1){
                cout<<"There are "<<top+1<<" students. And their marks are as follows: "<<endl;
                for(int i=0;i<=top;i++)
                s1[i].marksheet();
            }
            //s1[top].marksheet();
            else
            cout<<"No students are present";
            break;
        }
        case 5:{
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