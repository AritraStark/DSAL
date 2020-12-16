#include<iostream>
using namespace std;
class COMPLEX{
	int real;
	int img;
	public:
		COMPLEX(int r = 0, int i =0)  {real = r;   img = i;} 
		void setV()
		{
			cin>>real>>img;
		}
		COMPLEX operator+(COMPLEX const &c)
		{
			COMPLEX co;
			co.real=real+c.real;
			co.img=img+c.img;
			return co;
		}
		COMPLEX operator-(COMPLEX const &c)
		{
			COMPLEX com;
			com.real=real-c.real;
			com.img=img-c.img;
			return com;
		}
		
		void print()
		{
			cout<<real<<"         i"<<img<<"\n";
		}
};
int main()
{
	COMPLEX f1,f2,f3;
while(1)
{
	cout<<"Enter :\n1 for addition\n2 for substraction\n3To quit\n";
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 3: {cout<<"Exiting ...\n";
		exit(0);
		break;}
		case 1: {cout<<"Enter real and img parts\n";
		 f1.setV();
		cout<<"Enter second real and img parts\n";
	
		f2.setV();
		f3=f1+f2;
		f3.print();
		break;}
		case 2:{ 
		cout<<"Enter real and img parts\n";
		 f1.setV();
		cout<<"Enter second real and img partsr\n";
	
		 f2.setV();
		 f3=f1-f2;
		f3.print();
		break;}
		
	}
}
}