#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<iterator>

using namespace std;

class Student{
    public:
    int roll,score;
    string name;
    Student(){
        cout<<"Enter roll, name, score:\n";
        cin>>roll>>name>>score;
    }
    bool operator<(const Student& t) const
    { 
        return (this->score > t.score); 
    } 
};

void showQ(set<Student> arr)
{
    for(auto i = arr.begin();i != arr.end();++i)
    cout<<"| Roll : "<<i->roll<<" Name : "<<i->name<<" Score : "<<i->score<<endl;
}



int main(){
    set<Student> arr;
    for(;;){
        cout<<"Enter : \n1. For entering a student to the queue\n2. For showing students\n3. To Exit\n";
        int c;
        cin>>c;
        switch(c){
            case 1:{
                Student temp;
                arr.insert(temp);
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