// Store the roll and score of the students in a map in the sorted order of roll. One
// should be able to retrieve the score for a given roll. Take the help of suitable STL
// class.

#include<iostream>
#include<map>
#include<algorithm>
#include<iterator>

using namespace std;

int main(){
    map <int,int> arr;
    for(;;){
        cout<<"Enter :\n1. To insert element to map\n2. To view the whole map\n3. To retrieve particular roll number\n4. To exit\n";
        int c;
        cin>>c;
        switch(c){
            case 1:{
                pair<int,int> temp;
                cout<<"Enter Roll and Score: \n";
                cin>>temp.first>>temp.second;
                arr.insert(temp);
                break;
            }
            case 2:{
                for(auto i = arr.begin();i!=arr.end();++i)
                cout<<"Roll : "<<i->first<<" Score : "<<i->second<<endl;                
                break;
            }
            case 3:{
                int x;
                cout<<"Enter roll to find\n";
                cin>>x;
                auto i = arr.find(x);
                if(i!=arr.end())
                cout<<"Roll : "<<i->first<<" Score : "<<i->second<<endl;
                else
                cout<<"Not found\n";
                break;
            }
            case 4:{
                cout<<"Exiting...";
                exit(0);
                break;
            }
            default:{

                break;
            }
        }
    }
    return 0;
}