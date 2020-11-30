//#include<bits/stdc++.h>
#include <stdio.h>
#include <iostream>
using namespace std;

void arrange(char name[][51],int age[],int n)
{
   int i,j,temp=0;
   char t[51];
     for(i=0;i<n-1;i++)
     {
       for(j=i+1;j<n;j++)
       {
          if(age[i]>age[j])
          {
             temp=age[i];
             age[i]=age[j];
             age[j]=temp;
             strcpy(t,name[i]);
             strcpy(name[i],name[j]);
             strcpy(name[j],t);
          }
       }
     }
}
void display(char name[][51],int age[],int n)
{
  int i,j;
  cout<<"_____________"<<endl;
  cout<<"Age             Name\n";
  cout<<"_____________"<<endl;
    for(i=0;i<n;i++)
     cout<<age[i]<<"             "<<name[i]<<endl;
}
int main()
{
   int n,i;
   cout<<"Enter the number of names to be listed:  ";
   cin>>n;
   int age[n];
   char name[n][51];
     for(i=0;i<n;i++)
     {
        cout<<"Enter name: ";
        cin>>name[i];
        cout<<("Enter age: ");
        cin>>age[i];
     }
     arrange(name,age,n);
     display(name,age,n);
    return 0;
}