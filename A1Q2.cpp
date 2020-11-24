#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{

	int* ptr;
	int n, i;
	cout<<"Enter number of elements:"<<endl;
	cin>>n;
	ptr = (int*)malloc(n * sizeof(int));
	if (ptr == NULL) {
		cout<<"Memory not allocated"<<endl;
		exit(0);
	}
	else {
		cout<<"Memory successfully allocated using malloc."<<endl;
		for (i = 0; i < n; ++i) {
			cout<<"Enter element "<<i+1<<endl;
			cin>>*(ptr+i);
		}
		cout<<"The elements of the array are: ";
		for (i = 0; i < n; ++i) {
			cout<<*(ptr+i)<<" ";
		}
	}

	return 0;
}
