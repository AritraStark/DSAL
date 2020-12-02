#include <stdio.h>
#include <conio.h>
#include <string.h>

struct data{
    int age;
    char name[51];
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
  printf("_____________\n");
  printf("Age             Name\n");
  printf("_____________\n");
    for(int i=0;i<n;i++)
     printf("%d             %s",arr[i].age,arr[i].name);
}
int main()
{
   int n,i;
   printf("Enter the number of names to be listed:  ");
   scanf("%d",&n);
   struct data arr[n];
   
    for(i=0;i<n;i++)
     {
        printf("Enter name: ");
        scanf("%s",&arr[i].name);
        printf("Enter age: ");
        scanf("%d",arr[i].age);
     }
     arrange(arr,n);
     display(arr,n);
    return 0;
}