#include <stdio.h> 
#include <iostream> 
using namespace std;

void aop(){
    int r, c, i, j, count; 
    cout<<"Enter rows and columns"<<endl;
    cin>>r>>c;
    int *arr[r]; 
    for (i=0; i<r; i++) 
         arr[i] = (int *)malloc(c * sizeof(int)); 
    cout<<"Enter the elements";
    count = 0; 
    for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
         cin>>arr[i][j];
  
    for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
         cout<<arr[i][j]; 
         cout<<endl;
  
}

void sp(){
    int r, c, i, j, count=0; 
    cout<<"Enter rows and columns"<<endl;
    cin>>r>>c;
    int *arr = (int *)malloc(r * c * sizeof(int)); 
    cout<<"Enter the elements";
    for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
         cin>>*(arr + i*c + j);
  
    for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
         cout<<*(arr + i*c + j); 
         cout<<endl;
}
  
int main() 
{ 
    aop();
    sp();
    return 0;
} 