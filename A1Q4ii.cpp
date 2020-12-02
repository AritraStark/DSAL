#include <stdio.h> 
#include <iostream> 
using namespace std;

void input(int r, int c, int *arr[]){
  printf("Enter the elements");
  for (int i = 0; i <  r; i++) 
      for (int j = 0; j < c; j++) 
         scanf("%d",arr[i][j]);
}

void output(int r, int c, int *arr[]){
  for (int i = 0; i <  r; i++) 
      for (int j = 0; j < c; j++) 
         printf("%d",arr[i][j]); 
         printf("\n");
}

void input(int r, int c, int *arr){
  printf("Enter the elements");
  for (int i = 0; i <  r; i++) 
      for (int j = 0; j < c; j++) 
         scanf("%d",&arr[i][j]);
}

void output(int r, int c, int *arr){
  for (int i = 0; i <  r; i++) 
      for (int j = 0; j < c; j++) 
         printf("%d",arr[i][j]); 
         printf("\n");
}

void aop(){
    int r, c, count; 
    printf("Enter rows and columns\n");
    scanf("%d%d",&r,&c);
    int *arr[r]; 
    for (int i=0; i<r; i++) 
         arr[i] = (int *)malloc(c * sizeof(int)); 
    count = 0; 
    input(r,c,*arr);
    output(r,c,*arr);  
}

void sp(){
    int r, c, count=0; 
    printf("Enter rows and columns\n");
    scanf("%d%d",&r,&c);
    int *arr = (int *)malloc(r * c * sizeof(int)); 
    input(r,c,arr);
    output(r,c,arr); 
}
  
int main() 
{ 
    aop();
    sp();
    return 0;
} 