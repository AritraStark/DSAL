#include<iostream>
#include<string>
using namespace std;

class Student{
    int roll,score;
    string name;
    public:
    Student(){
        roll = 0;
        score = 0;
        name = "";
    }
    void input(){
        cout<<"Enter Roll, Name and Score\n";
        cin>>roll>>name>>score;
    }
    void display(){
        cout<<"Roll: "<<roll<<" | Name: "<<name<<" | Score: "<<score<<endl;
    }
};

int main(){
    for(;;){
        strt:
        cout<<"Enter :\n1. For array of objects initialization and operations\n2. To Exit\n";
        int c1,c2;
        cin>>c1;
        switch(c1){
            case 1:{
                Student *arr;
                cout<<"Enter length of array of objects:\n";
                int x;
                cin>>x;
                arr = new Student[x];
                for(;;){
                    cout<<"Enter :\n1. For taking input of all elements in array of objects\n2. For displaying i'th object in array of objects\n3. For displaying all elements of array of objects\n4. To go back to main menu\n";
                    cin>>c2;
                    switch(c2){
                        case 1:{
                            
                            for(int i=0;i<x;i++)
                            arr[i].input();
                            break;
                        }
                        case 2:{
                            cout<<"Enter index:\n";
                            int y;
                            cin>>y;
                            if(y>x||y<0){
                                cout<<"Out of bounds, invalid position\n";
                                break;
                            }
                            else{
                                cout<<"The "<<y<<"'th object in array:\n";
                                arr[y].display();
                                break;
                            }
                            break;
                        }
                        case 3:{
                            cout<<"All elements in array of objects: \n";
                            for(int i=0;i<x;i++){
                                cout<<i+1<<" . ";
                                arr[i].display();
                            }
                            break;
                        }
                        case 4:{
                            goto strt;
                        }
                        default:{
                            cout<<"Wrong Input";
                            break;
                        }
                    }
                }
                
                break;
            }
            case 2:{
                cout<<"Exiting ... ";
                exit(0);
            }
            default:{
                cout<<"Wrong Input";
                break;
            }
        }
    }
    return 0;
}