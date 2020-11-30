#include <stdio.h>
#include <iostream>
//#include<bits/stdc++.h>
using namespace std;

struct node{
    int roll;
    string name;
    double score[5];
};

void input(){
    fstream myfile;
    myfile.open("data.dat",ios::out|ios::app);
    struct node n1;
    cout<<"Enter unique roll:"<<endl;
    cin>>n1.roll;
    cout<<"Enter name:"<<endl;
    cin>>n1.name;
    cout<<"Enter marks for 5 subjects:"<<endl;
    for(int i=0;i<5;i++){
        cout<<i+1<<": ";
        cin>>n1.score[i];
        cout<<endl;
    }
    myfile.write((char*)&n1,sizeof(n1));
    myfile<<endl;
    myfile.close();
}

void search(){
    int query;
    cout<<"Roll for search"<<endl;
    cin>>query;
    fstream myfile;
    myfile.open("data.dat",ios::in);
    // while(){
    //     if(roll==query){
            
    //     }
    // }
    myfile.close();

}

void display(){
    struct node n3;
    fstream myfile;
    myfile.open("data.dat",ios::in);

    while(!myfile.eof()){
        myfile.read((char*)&n3,sizeof(n3));
        cout<<n3.roll<<" ";
        cout<<n3.name<<" ";
        cout<<endl;
    }
}

int main(){

    for(;;){
        int s;
        cout<<"Enter :";
        cin>>s;
        switch (s)
        {
            case 1:{
                input();
                break;
            }
                
            case 2:{
                display();
                break;
            }

            case 3:{
                search();
                break;
            }

            case 0:{
                exit(0);
                break;
            } 
            default:
                cout<<"Default";
                break;
        }
    }
    return 0;
}