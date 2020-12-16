#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class TIME{
    private:
    long int inp;
    int hour,min,sec;
    string ap;
    bool pk,ok;

    public:
    void extract(){
        sec=inp%100;
        min=(inp/100)%100;
        hour=inp/10000;
        check();
    }

    void check(){
        if(pk){
            if(hour<0||hour>24||min<0||min>59||sec<0||sec>59){
            cout<<"Wrong Input Program Closing ...";
            exit(0);
            }
        }
        else{
            if(hour<0||hour>12||min<0||min>59||sec<0||sec>59){
            cout<<"Wrong Input Program Closing ...";
            exit(0);
            }
        }
        
    }

    void i24(){
        cout<<"Enter time in HHMMSS format"<<endl;
        cin>>inp;
        extract();
        
    }

    void i12(){
        cout<<"Enter only time in HHMMSS format"<<endl;
        cin>>inp;
        cout<<"Enter AM or PM"<<endl;
        cin>>ap;
        extract();
        //check();
        if(ap[0]=='P'||ap[0]=='p')
        hour+=12;
    }

    void o24(){
        cout<<"Time is  "<<hour<<":"<<min<<":"<<sec<<endl;
    }

    void o12(){
        if(hour>12)
        cout<<"Time is  "<<hour-12<<":"<<min<<":"<<sec<<" PM"<<endl;
        else
        cout<<"Time is  "<<hour<<":"<<min<<":"<<sec<<" AM"<<endl;
    }

    void input(){
        cout<<"Enter 1 for 24 hour format entry and 0 for 12 hour format entry: "<<endl;
        cin>>pk;
        if(pk)
        i24();
        else
        i12();
    }

    void output(){
        cout<<"Enter 1 for 24 hour format entry and 0 for 12 hour format output: "<<endl;
        cin>>ok;
        if(ok)
        o24();
        else
        o12();
        
    }
};

int main(){
    TIME t1;
    for(;;){
        cout<<"Enter : \n1 To take Time input\n2.To show Time output\n3.To exit\n";
        int c;
        cin>>c;
        switch(c){
            case 1:{
                t1.input();
                break;
            }
            case 2:{
                t1.output();
                break;
            }
            case 3:{
                cout<<"Exiting ...\n";
                exit(0);
            }
            default:{
                cout<<"Wrong input";
                break;
            }
        }
    }
    
    
    return 0;   
}