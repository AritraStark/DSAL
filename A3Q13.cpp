#include <iostream>
#include <string>

using namespace std;

class NODE{
    //Node initialize
    public:
        int data;
        NODE *link;
};

class LIST{
    //List Initialize
    private:

    NODE* head;
    
    public:
        LIST(){
            head = NULL;
        }

        
        void addNodeHead(int x){
            //Add at first
            NODE* temp = new NODE;
            temp->data = x;
            temp->link = head;
            head = temp;
            print();
        }

        void insert(int x, int n){
            //Insert at n'th
            NODE* temp1 = new NODE;
            temp1->data = x;
            temp1->link = NULL;
            if(n==1){
                temp1->link = head;
                head = temp1;
                return;
            }
            NODE* temp2;
            temp2 = head;
            for(int i =0; i<n-2; i++)
            temp2 = temp2->link;
            temp1->link = temp2->link;
            temp2->link = temp1;
            print();
        }

        void addEnd(int data){
            //Add at end
            NODE *temp = new NODE;
            temp->data = data;
            temp->link = NULL;

            if(head == NULL)
            head = temp;
            else
            {
                NODE *temp2;
                temp2 = head;
                while(temp2->link != NULL)
                temp2 = temp2->link;
                temp2->link = temp;
            }
            print();
        }

        void deleteN(int n){
            //Delete n'th node
            NODE* temp1;
            temp1 = head;
            for(int i=0;i<n-2;i++)
            temp1 = temp1->link;
            NODE* temp2 = temp1->link;
            temp1->link = temp2->link;
            delete(temp2);
            print();
        }

        void print(){
            //Print all
            NODE* temp;
            temp = head;
            while(temp->link!=NULL){
                cout<<temp->data<<" -> ";
                temp=temp->link;
            }
            cout<<temp->data<<" -> ";
            cout<<endl;
        }


        
};

int main(){
    LIST l;
    
    for(;;){
        int s;
        cout<<"\nEnter: 1 for Insert At End\n2 for Insert at Head\n3 for deleting at n'th position\n4 for inserting at n'th position\n5 for printing the list\n6 to exit\n ";
        cin>>s;
        switch (s)
        {
            case 1:{
                int data;
                cout<<"Enter data to insert at end\n";
                cin>>data;
                l.addEnd(data);
                break;
            }
            case 2:{
                int data;
                cout<<"Enter data to insert at head\n";
                cin>>data;
                l.addNodeHead(data);
                break;
            }
            case 3:{
                int n;
                cout<<"Enter position to delete\n";
                cin>>n;
                l.deleteN(n);
                break;
            }
            case 4:{
                int data,n;
                cout<<"Enter data to insert\n";
                cin>>data;
                cout<<"Enter position to insert\n";
                cin>>n;
                l.insert(data,n);
                break;
            }
            case 5:{
                cout<<"The list is:\n";
                l.print();
                break;
            }
            case 6:{
                cout<<"Exiting ....";
                exit(1);
                break;
            }
            default:
                cout<<"Invalid Input";
                break;
        }
    }
    return 0;
}