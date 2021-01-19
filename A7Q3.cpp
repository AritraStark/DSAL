#include<iostream>
#include<string>
#include<queue>

using namespace std;

class Student{
    public:
    int roll,score;
    string name;
    bool marksheet;
    Student(){
        cout<<"Enter roll, name, score:\n";
        cin>>roll>>name>>score;
        marksheet = true;
    }
    void show(){
        cout<<"| Roll : "<<roll<<" Name : "<<name<<" Score : "<<score;
        marksheet?cout<<" Marksheet Issued | ":cout<<"Marksheet not issued | ";
    }
};

void showQ(queue<Student> gq)
{
    queue<Student> g = gq;
    while (!g.empty()) {
        g.front().show();
        g.pop();
        cout<<"     ->      ";
    }
    // cout << '\n';
}

int main(){
    queue<Student> arr;
    for(;;){
        cout<<"Enter : \n1. For entering a student to the queue\n2. For showing queue\n3. To Exit\n";
        int c;
        cin>>c;
        switch(c){
            case 1:{
                Student temp;
                arr.push(temp);
                break;
            }
            case 2:{
                showQ(arr);
                break;
            }
            case 3:{
                cout<<"Exiting...";
                exit(0);
                break;
            }
            default:{
                cout<<"Wrong Input\n";
                break;
            }
        }
    }
    return 0;
}