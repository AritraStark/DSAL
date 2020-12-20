#include<iostream>
#include<string>
using namespace std;

class Cricketer{
    private:
    int dob,match;
    string name;
    public:
    
    void setDeet(){
        int x,z;
        string y;
        cout<<"Enter Name, DOB and matches played\n";
        cin>>y>>x>>z;
        dob = x;
        match = z;
        name = y;
    }

    void getDeet(){
        cout<<"Name of player: "<<name<<"  Total no of matches played: "<<match<<"  Date of birth: "<<dob<<endl;
    }
};


class Bowler: public Cricketer{
    private:
    int wickets,avgEco;
    public:
    Bowler(){
        setDeet();
    }
    void setBolwer(){
        int x, y;
        cout<<"Enter Total Wickets and Average economy of Bowler\n";
        wickets = x;
        avgEco = y;
    }
    
    void getBowler(){
        getDeet();
        cout<<"Total wickets taken: "<<wickets<<" .Average economy: "<<avgEco<<endl;
    }
};

class Batsman: public Cricketer{
    private:
    int total,avgRun;
    public:
    Batsman(){
        setDeet();
    }
    void setBatsman(){
        int x, y;
        cout<<"Enter Total Runs and Average runs of Batsman\n";
        cin>>x>>y;
        total = x;
        avgRun = y;
    }
    
    void getBatsman(){
        getDeet();
        cout<<"Total runs scored: "<<total<<" .Average runs scored: "<<avgRun<<endl;
    }
};


class Pair{
    Batsman a;
    Bowler b;
    public:
    Pair(){
        a.setBatsman();
        b.setBolwer();
    }
    void showPair(){
        a.getBatsman();
        cout<<"___________________________\n";
        b.getBowler();
    }
};

class AllRounder:public Batsman,public Bowler{
    public:
    AllRounder(){
        setBatsman();
        setBolwer();       
    }
    void getAllrounder(){
        getBatsman();
        getBowler();
    }
};

int main(){
    for(;;){
        cout<<"Enter :\n1. For Batsman \n2. For Bowler\n3. For All Rounder\n4. For Pair\n5. Exit\n";
        int c;
        cin>>c;
        switch(c){
            case 1:{
                Batsman t;
                t.setBatsman();
                cout<<"Details of Batsman:\n";
                t.getBatsman();
                break;
            }
            case 2:{
                Bowler t;
                t.setBolwer();
                cout<<"Details of Bowler:\n";
                t.getBowler();
                break;
            }
            case 3:{
                AllRounder t;
                cout<<"Details of All Rounder:\n";
                t.getAllrounder();
                break;
            }
            case 4:{
                Pair t;
                cout<<"Details of Pair:\n";
                t.showPair();
                break;
            }
            case 5:{
                cout<<"Exiting ...";
                exit(0);
            }
        }
    }
    return 0;
}