#include <stdio.h>
#include <iostream>
using namespace std;


int dimensions(int n){
    cout<<"Enter number of elements:"<<endl;
	cin>>n;
    return n;
}

void accept(int n, int *ptr){
    //cout<<n;
    for (int i = 0; i < n; ++i) {
			cout<<"Enter element "<<i+1<<endl;
			cin>>*(ptr+i);
		}
}

void print(int n, int *ptr){
    cout<<"The elements of the array are: ";
		for (int i = 0; i < n; ++i) {
			cout<<*(ptr+i)<<" ";
		}
}

void allocate(int n,int *ptr){
    ptr = (int*)malloc(n * sizeof(int));
	if (ptr == NULL) {
		cout<<"Memory not allocated"<<endl;
		exit(0);
	}
	else {
		cout<<"Memory successfully allocated using malloc."<<endl;
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