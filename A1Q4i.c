#include <stdio.h>
#include <stdlib.h>
void read_dim(int *, int *);
void dm_alloc(int **, int);
void read_val(int **, int, int);
void print_val(int **, int, int);
int main()
{
    int r, c, *b[30];
    read_dim(&r, &c);
    for (int i = 0; i < r; ++i){
        dm_alloc(b + i, c);
    }
    read_val(b, r, c);
    print_val(b, r, c);
    for (int i = 0; i < r; ++i)
        free(b[i]);
    return 0;
}
void read_dim(int *m, int *n)
{
    printf("Enter the size of row and column  of array\n");
    scanf("%d%d", m, n);
}
void dm_alloc(int **ele, int len)
{
    *ele = (int *)malloc(len * sizeof(int)); 
        
}
void read_val(int **arr, int m, int n)
{
    printf("Enter values of array elements \n");
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", arr[i] + j);
}
void print_val(int **arr, int m, int n)
{
    printf("Values of the elements of the array\n");
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%d ", *(*(arr + i) + j));
        printf("\n");
    }
}
