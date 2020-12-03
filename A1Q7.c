#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
void Insert(char [], int , int );
void remove1(int roll);
void display();
int CheckEmpty();
struct Node{
 char name [20];
int roll;
int score;
struct Node *next;//*head=NULL;
};struct Node* head=NULL;


int main()
{
 int rl,choice,scr;
 char nm[20];
 
 char c;

 do{
         printf("Enter 1 for insert 2 for remove 3 for display\n");
         scanf("%d",&choice);
 switch(choice)
 {
  case 1:
  {
   int x,roll;
   fflush(stdin);
   printf("Enter Value to be Insertedthat is Name, Roll  No, Score of the student\n");
   gets(nm);
   scanf("%d",&roll);
   scanf("%d",&scr);
   Insert(nm,roll,scr);
     break;
    case 2:
    
     printf("Enter roll to be removed starting from 1\n");
     scanf("%d",&rl);
     remove1(rl);
     break;
    
    case 3:
    display();
   break;
  }
  default:
  {
   printf("Not A Valid Choice\n");
   break;
  }
 }
 printf("Press y to continue else any letter\n");
 fflush(stdin);
 c=getche();
 printf("\n");
 }while(c=='Y' || c=='y');
 
 return(0);
}

void Insert(char nm[], int roll, int scr){
   struct Node *newNumber;
   struct Node *temp,*temp1;
   int f=0;
   newNumber = (struct Node*)malloc(sizeof(struct Node));
  
 if(head==NULL)
 { 
 newNumber->roll = roll;
   newNumber->score=scr;
   strcpy(newNumber->name,nm);
   newNumber->next=NULL;
  head=newNumber;
 }
 
  else
  {
  temp=head;	
  while(temp->next!=NULL)
  {
   temp=temp->next;
  }
   newNumber->roll = roll;
   newNumber->score=scr;
   strcpy(newNumber->name,nm);
   newNumber->next=NULL;
  temp->next=newNumber;
  newNumber=temp;
 }
}


void remove1(int roll){
 
 int flag=CheckEmpty();
 struct node *temp1;
 if(flag==1)
 {
      struct Node *temp,*prev;
     temp=head;
     
      while(temp->next!=NULL)
     {
    
     	if(temp->roll==roll)
     	{
     		prev->next=temp->next;
     		temp=temp->next;
     		break;
		}
      temp=temp->next;
      
      }
     prev=temp; 
 }
 
else
{
  printf("List is empty\n");
 }
 
}

void display(){
 int flag=CheckEmpty();
 if(flag==1)
 {
      struct Node *temp;
     temp=head;
      while(temp->next!=NULL)
     {
      printf("%d %s %d\n",temp->roll,temp->name,temp->score);
      temp=temp->next;
      }
      printf("%d %s %d",temp->roll,temp->name,temp->score);
        printf("\n");
 }
 else
 {
  printf("Not Available\n");
 }
}

int CheckEmpty()
{
 if(head==NULL)
 return 0;
 else
 return 1;
}
