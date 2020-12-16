#include<iostream>
#include<string>
using namespace std;

class Account{
    public:
    int acNo;
    unsigned long int bnc;
    Account* next;

    friend void withdraw(Account*);
};

void withdraw(Account *a){
        cout<<"Enter money to withdraw: \n";
        long int bnc1;
        cin>>bnc1;
        if(a->bnc>=bnc1){
            a->bnc-=bnc1;
            cout<<"Remaining balance: "<<a->bnc<<endl;
        }
        
        else
        cout<<"Unsufficient balance\n";
}

class AcList{
    private:
    Account* head;
    public:
    AcList(){
        head = NULL;
    }
    void push(int a,int b){
        Account* temp = new Account;
        temp->acNo = a;
        temp->bnc = b;
        temp->next = NULL;
        if(head == NULL)
        head = temp;
        else{
            Account* temp1;
            temp1 = head;
            while(temp1->next=NULL){
                if(!checkUnique(a)){
                    cout<<"Account already exists\n";
                    return;
                }
                temp1=temp1->next;
            }
            
            temp1->next = temp;
        }
    }

    bool checkUnique(int acNo1){
        Account* temp;
        temp = head;
        if(head==NULL)
        return true;
        while(temp!=NULL){
            if(temp->acNo == acNo1)
            return false;
            temp = temp->next; 
        }

        return true;
    }

    void display(){
        Account* temp ;
        temp = head;
        while(temp!=NULL){
            cout<<"Account Number: "<<temp->acNo<<" Balance: "<<temp->bnc<<endl;
            temp = temp->next; 
        }
    }

    

    void with(int acNo1){
        Account* temp ;
        temp = head;
        while(temp!=NULL){
            if(temp->acNo==acNo1)
            withdraw(temp);
            temp = temp->next; 
        }
        cout<<"Acount does not exist";
    }
    
    
};



int main(){
    AcList a1;
    for(;;){
        cout<<"Enter : \n1. To open an account\n2. To withdraw money\n3. Display all acoounts \n4. Exit\n";
        int s;
        cin>>s;
        switch(s){
            case 1:{
                cout<<"Enter account number and balance\n";
                int a;
                unsigned long int b;
                cin>>a>>b;
                a1.push(a,b);
                break;
            }
            case 2:{
                cout<<"Enter account number for withdrawl:\n";
                int a;
                cin>>a;
                a1.with(a);
                break;
            }
            case 3:{
                cout<<"List :\n";
                a1.display();
                break;
            }
            case 4:{
                cout<<"Exiting...\n";
                exit(0);
            }
            default:{
                cout<<"wrong input \n";
                break;
            }
        }
    }
    return 0;
}