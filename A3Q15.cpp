#include<iostream>
#include<string>
using namespace std;

// class TRANSACTION:public BALANCE{
//     public:
//     int accNum;
//     unsigned long int amount;
//     string date;
//     char type;
    
//     void withdraw(){
//         cout<<"Enter account number, amount and date \n";
//         cin>>accNum>>amount>>date;
//         type='W';
//         if(getBal()<amount){
//             cout<<"Insufficient Balance";
//             return;
//         }
//         else{
//             setBal(amount,type);
//             setDate(date);
//         }
//     }

//     void deposit(){
//         cout<<"Enter account number, amount and date \n";
//         cin>>accNum>>amount>>date;
//         type='D';
//         setBal(amount,type);
//         setDate(date);

//     }

// };

class BALANCE{
    private:
    int accNum;
    unsigned long int balance;
    string date;

    public:

    BALANCE(){
        accNum=0;
        balance=0;
        date="";
    }


    int getAcc(){
        return accNum;
    }
    void setAcc(int x){
        accNum = x;
    }
    void setBal(unsigned long int x, char type){
        if(type=='W')
        balance -= x;
        else if(type=='D')
        balance+=x;
    }
    int getBal(){
        return balance;
    }
    string getDate(){
        return date;
    }
    void setDate(string x){
        date = x;
    }
    void display(){
        cout<<"\nAccount Number: "<<getAcc()<<"\nBalance: "<<getBal()<<"\nDate of last update: "<<getDate();
    }

};

class TRANSACTION{
    private:
    BALANCE b[100];
    int n=0;
    public:
    unsigned long int amount;
    string date;
    char type;
    
    void initAcc(){
        cout<<"Enter Account Number to open an account\n";
        int acc;
        cin>> acc;
        b[n].setAcc(acc);
        b[n].display();
        n++;
    }

    void withdraw(){
        cout<<"Enter account number, amount and date \n";
        int acc;
        cin>>acc>>amount>>date;
        type='W';
        for(int i=0;i<n;i++){
            if(b[i].getAcc()==acc){
                if(b[i].getBal()<amount){
                    cout<<"Insufficient Balance\n";
                    return;
                }
                else{
                    b[i].setBal(amount,type);
                    b[i].setDate(date);
                    b[i].display();
                    return;
                }
            }
        }
        cout<<"Account not found\n";
        return;
    }

    void deposit(){
        cout<<"Enter account number, amount and date \n";
        int acc;
        cin>>acc>>amount>>date;
        type='D';
        for(int i=0;i<n;i++){
            if(b[i].getAcc()==acc){
                b[i].setBal(amount,type);
                b[i].setDate(date);
                b[i].display();
                return;
            }
        }
        cout<<"Account not found\n";
        return;

    }

};

int main(){
    TRANSACTION t;
    for(;;){
        int s;
        cout<<"\nEnter : \n1 to open an Account\n2 to Withdraw money\n3 to Deposit money\n4 to Exit\n";
        cin>>s;
        switch(s){
            case 1:{
                t.initAcc();
                break;
            }
            case 2:{
                t.withdraw();
                break;
            }
            case 3:{
                t.deposit();
                break;
            }
            case 4:{
                cout<<"Exiting...";
                exit(1);
            }
            default:{
                cout<<"Wrong Input\n";
                break;
            }
        }
    }
    return 0;
}