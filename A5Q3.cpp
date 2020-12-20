#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Employee{
    // int empId;
    string name,desig;
    public:
    int empId;
    int basicPay,finalPay;
    void show(){
        cout<<"Employee ID: "<<empId<<" | Employee Name: "<<name<<" | Employee Designation: "<<desig<<" | Employee Basic-Pay: "<<basicPay<<" | Employee Final-Pay "<<finalPay<<endl;
    }
    void get(){
        cout<<"Enter Employee ID, Name, Designation, Basic-Pay\n";
        cin>>empId>>name>>desig>>basicPay;
    }
    // int getId(){return empId;}
};

class Permanent: public Employee{
    public:
    Permanent* next;
    Permanent(){
        get();
    }
    void genFinal(){
        finalPay = basicPay + 0.3*basicPay +0.8* basicPay;
    }
};

class Temporary: public Employee{
    public:
    Temporary* next;
    Temporary(){
        get();
    }
    int allowance;
    void genFinal(){ 
        cout<<"Enter allowance: \n";
        cin>>allowance;
        finalPay = basicPay + allowance;
    }
};

class PermList{
    Permanent* head;
    public:
    PermList(){
        head = NULL;
    }
    bool checkUnique(int x){
        //cout<<"Checking\n";
        Permanent* temp;
        temp = head;
        if(head==NULL)
        return true;
        while(temp!=NULL){
            if(temp->empId==x)
            return false;
            temp = temp->next; 
        }

        return true;
    }
    void push(){
        Permanent* temp = new Permanent;
        temp->next = NULL;
        temp->genFinal();
        cout<<"Account Created\n";
        if(head == NULL){
            
            head = temp;
        }
        
        else{
            Permanent* temp1;
            temp1 = head;
            while(temp1->next!=NULL){
                if(!checkUnique(temp->empId)){
                    cout<<"Account already exists\n";
                    return;
                }
                temp1=temp1->next;
            }
            if(!checkUnique(temp->empId)){
                cout<<"Account already exists\n";
                return;
            }
            temp1->next = temp;
        }
    }
    void display(){
        Permanent* temp ;
        temp = head;
        while(temp!=NULL){
            temp->show();
            temp = temp->next; 
        }
    }
};

class TempList{
    Temporary* head;
    public:
    TempList(){
        head = NULL;
    }
    bool checkUnique(int x){
        //cout<<"Checking\n";
        Temporary* temp;
        temp = head;
        if(head==NULL)
        return true;
        while(temp!=NULL){
            if(temp->empId==x)
            return false;
            temp = temp->next; 
        }

        return true;
    }
    void push(){
        Temporary* temp = new Temporary;
        temp->next = NULL;
        temp->genFinal();
        cout<<"Account Created\n";
        if(head == NULL){
            
            head = temp;
        }
        
        else{
            Temporary* temp1;
            temp1 = head;
            while(temp1->next!=NULL){
                if(!checkUnique(temp->empId)){
                    cout<<"Account already exists\n";
                    return;
                }
                temp1=temp1->next;
            }
            if(!checkUnique(temp->empId)){
                cout<<"Account already exists\n";
                return;
            }
            temp1->next = temp;
        }
    }
    void display(){
        Temporary* temp ;
        temp = head;
        while(temp!=NULL){
            temp->show();
            temp = temp->next; 
        }
    }
};


int main(){
    PermList v1;
    TempList v2;
    for(;;){
        cout<<"Enter :\n1. To create new Permanent Employee\n2. to create new Temporary Employee\n3. To show all Employees\n4. To Exit\n";
        int c;
        cin>>c;
        switch(c){
            case 1:{
                v1.push();
                break;
            }
            case 2:{
                v2.push();
                break;
            }
            case 3:{
                cout<<"Permanent Employees:\n";
                v1.display();
                cout<<"Temporary Employees:\n";
                v2.display();
                break;
            }
            case 4:{
                cout<<"Exiting ... ";
                exit(0);
            }
            default:{
                cout<<"Wrong Input\n";
                break;
            }
        }
    }   
    return 0;
}