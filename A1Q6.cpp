#include <stdio.h>
#include <iostream>
//#include<bits/stdc++.h>
using namespace std;

struct data{
    int age;
    string name;
};



void arrange(struct data arr[],int n)
{
   struct data temp;
   char t[51];
     for(int i=0;i<n-1;i++)
     {
       for(int j=i+1;j<n;j++)
       {
          if(arr[i].age>arr[j].age)
          {
             temp=arr[i];
             arr[i]=arr[j];
             arr[j]=temp;
          }
       }
     }
}
void display(struct data arr[],int n)
{
  cout<<"_____________"<<endl;
  cout<<"Age             Name\n";
  cout<<"_____________"<<endl;
    for(int i=0;i<n;i++)
     cout<<arr[i].age<<"             "<<arr[i].name<<endl;
}
int main()
{
   int n,i;
   cout<<"Enter the number of names to be listed:  ";
   cin>>n;
   struct data arr[n];
   
    for(i=0;i<n;i++)
     {
        cout<<"Enter name: ";
        cin>>arr[i].name;
        cout<<("Enter age: ");
        cin>>arr[i].age;
     }
     arrange(arr,n);
     display(arr,n);
    return 0;
}