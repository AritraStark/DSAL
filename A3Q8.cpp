#include <iostream>
using namespace std;

struct stud{
    int roll;
    double score;

    void inpt(struct stud &temp){
        cout<<"Enter roll and score"<<endl;
        cin>>temp.roll>>temp.score;
    }

    void dis(struct stud &temp){
        cout<<"Roll is : "<<temp.roll<<" and score is : "<<temp.score<<endl;
    }
};

void modify(struct stud &temp){
    cout<<"Enter new score"<<endl;
    cin>>temp.score;
}

void display(struct stud &temp){
    cout<<"Roll is : "<<temp.roll<<" and score is : "<<temp.score<<endl;
}

int main(){
    struct stud a;
    for(;;){
        cout<<"Enter : \n1 To take input\n2. To display\n3. To modify\n4. To display(global)\n5.To exit\n";
        int c;
        cin>>c;
        switch(c){
            case 1:{
                a.inpt(a);
                break;
            }
            case 2:{
                a.dis(a);
                break;
            }
            case 3:{
                modify(a);
                break;
            }
            case 4:{
                display(a);
                break;
            }
            case 5:{
                cout<<"Exiting ...\n";
                exit(0);
            }
            default:{
                cout<<"Wrong input";
                break;
            }
        }
    }
    
    
    
    display(a);
    return 0;
}