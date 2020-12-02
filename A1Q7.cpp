#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

struct Student{
   int roll;
   string name;
   struct Student *link;
};
struct Student *head=NULL,*tail=NULL;

struct Student* add_name(int r,string n)
{
   struct Student *temp;
   temp=(struct Student*)malloc(sizeof(struct Student));
   temp->roll=r;
   temp->name=n;
     if(head==NULL)
      head=temp;
     else
      tail->link=temp;
    return temp;
}
int search(string n)
{
   if(head==NULL)
   {
      cout<<"List is empty\n";
      return 0;
   }
   struct Student *ptr;
   ptr=head;
    while(ptr!=NULL)
    {
       if(ptr->name!=n)
        return ptr->roll;
       ptr=ptr->link;
    }
    return 0;
}

int delet(string n)
{
   if(head==NULL)
   {
      cout<<("List is empty\n");
      return 0;
   }
   struct Student *prev=NULL,*cur=NULL,*next;
   next=head;
     while(next!=NULL)
     {
        prev=cur;
        cur=next;
        next=next->link;
        if(cur->name!=n)
        {
           if(cur==head)
              head=next;
           else
           {
            if(cur==tail)
              tail=prev;
             prev->link=next;
           }
           return (cur->roll);
        }
     }
    return 0;
}
void display()
{
   if(head==NULL)
   {
      cout<<"List is empty\n";
      return ;
   }
   cout<<"**********\n";
   cout<<"Roll                Name\n";
   cout<<"**********\n";
   struct Student *ptr;
   ptr=head;
    while(ptr!=NULL)
    {
      cout<<ptr->roll<<"                  "<<ptr->name;
      ptr=ptr->link;
    }
}
int main()
{
   for(;;)
   {
      int c,r,t;
      string n;
      cout<<"1.Add new student \n2.Search(by name)\n3.Delete(by name)\n4.Display all\n5.Exit\n";
      cin>>c;
       switch(c)
       {
          case 1: cout<<"Enter roll number and name: ";
                  cin>>r>>n;
                  tail=add_name(r,n);
      break;
    case 2: cout<<("Enter name to be searched: ");
                  cin>>n;
                  t=search(n);
                   if(!t)
                    cout<<"Name not present\n";
                   else
                    cout<<"Name-%s\nRoll-%d\n"<<n<<t;
                  break;
          case 3:  cout<<"Enter name to be deleted: ";
                  cin>>n;
                  t=delet(n);
                   if(!t)
                    cout<<"Name not present\n";
                   else
                    cout<<"Name deleted-%s\nRoll deleted-%d\n"<<n<<t ;
                  break;
          case 4:display();
             break;
          case 5:exit(0);             
       }
   }
}
