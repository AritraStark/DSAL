#include<bits/stdc++.h>
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
    struct stud a,b;
    a.inpt(a);
    a.dis(a);
    modify(a);
    display(a);
    return 0;
}