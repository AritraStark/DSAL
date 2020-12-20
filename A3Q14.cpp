
// 14.	Design  the class(es) for the following scenario:
// •	An item list contains item code, name, rate, and quantity for several items.
// •	Whenever a new item is added in the list uniqueness of item code is to be checked. 
// •	Time to time rate of the items may change. 
// •	Whenever an item is issued or received existence of the item is checked and quantity is updated. 
// •	In case of issue, availability of quantity is also to be checked.
// •	User may also like to know price/quantity available for an item.

#include<iostream>
#include<string>

using namespace std;


class Item{
    //Item Node initialize
    
    public:
    int code,rate,quantity;
    string name;
    Item *next;
};

class ItemList{
    //Item list initialize
    private:
    Item* head;
    int n;
    public:
    ItemList(){
        head = NULL;
        n=0;
    }
    void insertItem(int code1,string name1,int rate1, int quantity1=0){
        Item* temp1 = new Item;
        temp1->code = code1;
        temp1->rate = rate1;
        temp1->name = name1;
        temp1->quantity = quantity1;
        temp1->next = NULL;
        if(head == NULL)
        head = temp1;
        else{
            Item* temp2;
            temp2 = head;
            while(temp2->next!=NULL)
            temp2=temp2->next;
            temp2->next=temp1;
        }
        n++;
        cout<<"Item inserted successfully\n";
    }
    bool checkUnique(int code1){
        Item* temp ;
        temp = head;
        if(head==NULL)
        return true;
        while(temp!=NULL){
            if(temp->code == code1)
            return false;
            temp = temp->next; 
        }

        return true;
    }
    int getRate(int code1){
        Item* temp ;
        temp = head;
        while(temp!= NULL){
            if(temp->code==code1)
            return temp->rate;
            temp = temp->next; 
        }

        return -1;
    }
    int getQuantity(int code1){
        Item* temp ;
        temp = head;
        while(temp!= NULL){
            if(temp->code==code1)
            return temp->quantity;
            temp = temp->next; 
        }
        return -1;
    }
    void updateRate(int code1,int rate1){
        Item* temp ;
        temp = head;
        while(temp!= NULL){
            if(temp->code==code1){
                temp->rate = rate1;
                cout<<"Rate has been updated\n";
                return;
            }
            
            temp = temp->next; 
        }
        cout<<"Item not found\n";
    }
    void recieve(int code1,int quantity2){
        Item* temp;
        temp = head;
        while(temp!= NULL){
            if(temp->code==code1){
                temp->quantity += quantity2;
                cout<<"Item recieved. Quantity has been updated to :"<<temp->quantity<< "\n";
                return;
            }
            
            temp = temp->next; 
        }
        cout<<"Item not found";
    }
    void issue(int code1,int quantity2){
        Item* temp ;
        temp = head;
        while(temp!= NULL){
            if(temp->code==code1){
                if(temp->quantity>=quantity2){
                    temp->quantity -= quantity2;
                    cout<<"Item issued. Quantity has been updated to :"<<temp->quantity<< "\n";

                    return;
                }
                else{
                    cout<<"Items insufficient for issuing \n";

                    return;
                }
            }
            
            temp = temp->next; 
        }

        cout<<"Item not found";
    }
    void show(){
        Item* temp;
        temp = head;
        cout<<"Items List\n";
        while(temp!=NULL){
            cout<<"Item Code: "<<temp->code<<" | Item Name: "<<temp->name<<" | Item Rate: "<<temp->rate<<" | Item Quantity: "<<temp->quantity;
            cout<<endl;
            temp = temp->next;
        }
    }
};

int main(){
    ItemList l;
    for(;;){
        cout<<"Enter :\n1 for Adding Item \n2 for getting Rate of an item\n3 for getting Quantity of an item\n4 for updating Rate of an item\n5 for issuing an item\n6 for recieving an item\n7. To show the Item List: \n8 to Exit\n ";
        int s;
        cin>>s;
        switch(s){
            case 1:{
                cout<<"Enter details of item in order(code,name,rate,quantity)\n";

                Item *temp= new Item;
                cin>>temp->code>>temp->name>>temp->rate>>temp->quantity;

                if(!l.checkUnique(temp->code)){
                    cout<<"Item code exists";
                    break;
                }
                else{
                    l.insertItem(temp->code,temp->name,temp->rate,temp->quantity);
                }
                delete(temp);
                break;
            }

            case 2:{
                cout<<"Enter Item Code to get rate\n";
                int x;
                cin>>x;
                if(l.getRate(x)==-1){
                    cout<<"Item does not exist in the list\n";
                    break;
                }
                else{
                    cout<<"The rate of the item is : "<<l.getRate(x)<<endl;
                    break;
                }
            }

            case 3:{
                cout<<"Enter Item Code to get quantity\n";
                int x;
                cin>>x;
                if(l.getQuantity(x)==-1){
                    cout<<"Item does not exist in the list\n";
                    break;
                }
                else{
                    cout<<"The quantity of the item is : "<<l.getQuantity(x)<<endl;
                    break;
                }
            }

            case 4:{
                cout<<"Enter Item code and rate to update\n";
                int a,b;
                cin>>a>>b;
                l.updateRate(a,b);
                break;
            }

            case 5:{
                cout<<"Enter Item code and quantity to issue\n";
                int a,b;
                cin>>a>>b;
                l.issue(a,b);
                break;
            }

            case 6:{
                cout<<"Enter Item code and quantity to recieve\n";
                int a,b;
                cin>>a>>b;
                l.recieve(a,b);
                break;
            }

            case 7:{
                l.show();
                break;
            }

            case 8:{
                cout<<"Exiting program\n";
                exit(1);
            }

            default:{
                cout<<"Wrong Input";
                break;
            }
        }
    }
}