#include <stdio.h>
#include <conio.h>

void aop(){
    int r, c, i, j, count; 
    printf("Enter rows and columns\n");
    scanf("%d%d",&r,&c);
    int *arr[r]; 
    for (i=0; i<r; i++) 
         arr[i] = (int *)malloc(c * sizeof(int)); 
    printf("Enter the elements");
    count = 0; 
    for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
         scanf("%d",&arr[i][j]);
  
    for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
         printf("%d",arr[i][j]); 
         printf("\n");
  
}

void sp(){
    int r, c, i, j, count=0; 
    printf("Enter rows and columns\n");
    scanf("%d%d",&r,&c);
    int *arr = (int *)malloc(r * c * sizeof(int)); 
    printf("Enter the elements");
    for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
         scanf("%d",(arr + i*c + j));
  
    for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
         printf("%d",*(arr + i*c + j)); 
         printf("\n");
}
  
int main() 
{ 
    aop();
    sp();
    return 0;
} 