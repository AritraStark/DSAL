#include <stdio.h>
#include <conio.h>


int dimensions(int n){
    printf("Enter number of elements:\n");
	scanf("%d",&n);
    return n;
}

void accept(int n, int *ptr){
    //printf(n;
    for (int i = 0; i < n; ++i) {
			printf("Enter element %d \n",i+1);
			scanf("%d",(ptr+i));
		}
}

void print(int n, int *ptr){
    printf("The elements of the array are: ");
		for (int i = 0; i < n; ++i) {
			printf("%d ",*(ptr+i));
		}
}

void allocate(int n,int *ptr){
    ptr = (int*)malloc(n * sizeof(int));
	if (ptr == NULL) {
		printf("Memory not allocated \n");
		exit(0);
	}
	else {
		printf("Memory successfully allocated using malloc. \n");
		accept(n,ptr);
		print(n,ptr);
	}
}

int main()
{

	int* ptr;
	int n, i;
	n = dimensions(n);
	allocate(n,ptr);

	return 0;
}