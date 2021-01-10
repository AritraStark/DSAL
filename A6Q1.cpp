/*In a library, for each book book-id, serial number (denotes copy number of a
book), title, author, publisher and price are stored. Book-id and serial number
together will be unique identifier for a book. Members are either student or
faculty. Each member has unique member-id. Name, e-mail, address are also to
be stored. For any transaction (book issue or return), members are supposed to
place transactions slip. User will submit member-id, book-id, and serial number
(only for book return). While processing a transaction, check the validity of the
member. While issuing, availability of a copy of the book is to be checked. While
returning a book, it is to be checked whether this copy was issued to the
member or not. A student member can have 2 books issued at a point of time.
For faculty members it is 10. Transaction information is to be stored like date of
transaction, member-id, book-id, serial number, returned or not. An entry is
made when book is issued and updated when the book is returned. For storing
the information consider files.
Design the classes and implement.*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

class Book{
    public:
    int b_id,s_no,price;
    string title,author,pub;
    vector<int> m_list;
    Book *next;
};

class Member{
    public:
    int m_id;
    string name,email;
    int count;
    char type;
    vector<int> b_list;
    Member *next;
};



class BookList{
    Book *head;
    
    public:
    BookList(){
        head = NULL;
    }
    void push(int x, int t,string y,string z, string p){
        Book *temp = new Book;
        temp->b_id = x;
        temp->s_no = 1;
        temp->title = y;
        temp->author = z;
        temp->pub = p;
        temp->price = t;
        temp ->next = NULL;
        if(head == NULL)
        head = temp;
        else{
            Book* temp1;
            temp1 = head;
            while(temp1->next=NULL){
                if(!checkUnique(x)){
                    cout<<"Book ID already exists, increasing the Serial Count\n";
                    temp1->s_no++;
                    return;
                }
                temp1=temp1->next;
            }
            
            temp1->next = temp;
        }
    }

    void display(){
        Book *temp1;
        temp1= head;
        while(temp1!=NULL){
            cout<<"Book ID : "<<temp1->b_id<<" Title: "<<temp1->title<<" Author: "<<temp1->author<<" Publisher: "<<temp1->pub<<" Serial No: "<<temp1->s_no<<" Price: "<<temp1->price<<endl;
            temp1=temp1->next;
        }
    }

    bool checkUnique(int acNo1){
        Book* temp;
        temp = head;
        if(head==NULL)
        return true;
        while(temp!=NULL){
            if(temp->b_id == acNo1)
            return false;
            temp = temp->next; 
        }

        return true;
    }

    void add_M_List(int x,int y){
        Book* temp;
        temp = head;
        while(temp!=NULL&&temp->b_id != y){
            temp = temp->next; 
        }
        temp->m_list.push_back(x);
    }
    void remove_M_List(int x,int y){
        Book* temp;
        temp = head;
        while(temp!=NULL&&temp->b_id != y){
            temp = temp->next; 
        }
        for (auto i =temp->m_list.begin();  i != temp->m_list.end(); ++i){
            if(*i==x){
                temp->m_list.erase(i);
                break;
            }
        }
    }

    void inc_count(int x){
        Book* temp;
        temp = head;
        while(temp!=NULL&&temp->b_id != x){
            temp = temp->next; 
        }
        temp->s_no++;
    }
    void dec_count(int x){
         Book* temp;
        temp = head;
        while(temp!=NULL&&temp->b_id != x){
            temp = temp->next; 
        }
        if(temp->s_no>0)
        temp->s_no--;
        else
        cout<<"Insufficient Books\n";
    }
};

class MemList{
    Member *head;
    
    public:
    MemList(){
        head = NULL;
    }
    void push(int x,string y,string z,char t){
        Member *temp = new Member;
        temp->m_id = x;
        temp->email = z;
        temp->name = y;
        temp->type = t;
        temp->count = 0;
        temp ->next = NULL;
        if(head == NULL)
        head = temp;
        else{
            Member* temp1;
            temp1 = head;
            while(temp1->next=NULL){
                if(!checkUnique(x)){
                    cout<<"Member already exists\n";
                    return;
                }
                temp1=temp1->next;
            }
            
            temp1->next = temp;
        }
    }

    void display(){
        Member *temp1;
        temp1= head;
        while(temp1!=NULL){
            cout<<"Member ID : "<<temp1->m_id<<" Email: "<<temp1->email<<" Name: "<<temp1->name<<endl;
            temp1=temp1->next;
        }
    }

    bool checkUnique(int acNo1){
        Member* temp;
        temp = head;
        if(head==NULL)
        return true;
        while(temp!=NULL){
            if(temp->m_id == acNo1)
            return false;
            temp = temp->next; 
        }

        return true;
    }

    void add_B_List(int y,int x){
        Member* temp;
        temp = head;
        while(temp!=NULL&&temp->m_id != y){
            temp = temp->next; 
        }
        if(temp->type == 's' && temp->count < 3)
        temp->b_list.push_back(x);
        else if(temp->type == 'f' && temp->count < 8)
        temp->b_list.push_back(x);
        else
        cout<<"Limit exceeded\n";
    }
    void remove_B_List(int y,int x){
        Member* temp;
        temp = head;
        while(temp!=NULL&&temp->m_id != y){
            temp = temp->next; 
        }
        for (auto i =temp->b_list.begin();  i != temp->b_list.end(); ++i){
            if(*i==x){
                temp->b_list.erase(i);
                break;
            }
        }
    }
};


class Transaction{
    public:
    BookList a;
    MemList a1;
    fstream fio;
    void addB(){
        fio.open("books.txt",ios::out | ios::app);
        int b,c;
        string d,e,f;
        cout<<"Enter Book ID, Title, Author, Publisher, Price:\n";
        cin>>b>>d>>f>>e>>c;
        a.push(b,c,d,e,f);
        fio<<b<<d<<f<<e<<c<<endl;
        fio.close();

    }
    void viewB(){
        fio.open("books.txt",ios::in);
        cout<<"The list of books are:\n";
        a.display();
        fio.close();
    }
    void addS(){
        fio.open("members.txt",ios::out | ios::app);
        int b;
        string d,e;
        cout<<"Enter Member ID, Name, Email:\n";
        cin>>b>>d>>e;
        fio<<b<<d<<e<<endl;
        a1.push(b,d,e,'s');
        fio.close();
    }
    void addM(){
        fio.open("members.txt",ios::out | ios::app);
        int b;
        string d,e;
        cout<<"Enter Member ID, Name, Email:\n";
        cin>>b>>d>>e;
        fio<<b<<d<<e<<endl;
        a1.push(b,d,e,'f');
        fio.close();
    }
    void viewM(){
        fio.open("members.txt",ios::in);
        cout<<"The list of Members are:\n";
        a1.display();
        fio.close();
    }

    void issue(){
        fio.open("transactions.txt",ios::out|ios::app);
        cout<<"Available Books:\n";
        a.display();
        int k,l;
        cout<<"Enter Book ID and Member ID\n";
        cin>>k>>l;
        fio<<"Book ID: "<<k<<" Member ID"<<l<<" Status: Issued"<<endl;
        a1.add_B_List(k,l);
        a.add_M_List(l,k);
        a.dec_count(k);
        cout<<"Book Issued\n";
        fio.close();
    }
    void retur(){
        fio.open("transactions.txt",ios::out|ios::app);
        int k,l;
        cout<<"Enter Book ID and Member ID\n";
        cin>>k>>l;
        fio<<"Book ID: "<<k<<" Member ID"<<l<<" Status: Returned"<<endl;
        a1.remove_B_List(k,l);
        a.remove_M_List(l,k);
        a.inc_count(k);
        cout<<"Book Returned\n";
        fio.close();
    }
};

int main(){
    Transaction t;
    for(;;){
        cout<<"Enter:\n1. Add a Book\n2. Add a Student\n3. Add a Faculty\n4. Issue a Book\n5. Return a Book\n6. Show all Books\n7. Show all Members\n8. Exit\n";
        int c;
        cin>>c;
        switch(c){
            case 1:{
                t.addB();
                break;
            }
            case 2:{
                t.addS();
                break;
            }
            case 3:{
                t.addM();
                break;
            }
            case 4:{
                t.issue();
                break;
            }
            case 5:{
                t.retur();
                break;
            }
            case 6:{
                t.viewB();
                break;
            }
            case 7:{
                t.viewM();
                break;
            }
            case 8:{
                cout<<"Exiting ... \n";
                exit(0);
            }
            default:{
                cout<<"Wrong choice\n";
                break;
            }
        }
    }
    return 0;
}