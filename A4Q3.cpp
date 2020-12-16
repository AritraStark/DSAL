#include<iostream>
#include<string>
using namespace std;

class ARRAY{
    private:
    int n;
    int *arr;

    public:
    // ARRAY(){
    //     arr = new int (0);
    // }
    ARRAY(int s=0,int x=0){
        if(s>0)
		{
			n=s;
			arr=new int[n];
			for(int i=0;i<n;i++)
				arr[i]=x;
		}
		else{
			n=0;
			arr=NULL;
		}
    }
    ARRAY(const ARRAY &a){
        n=a.n;
        arr = new int(n);
        for(int i=0;i<a.n;i++)
        arr[i] = a.arr[i];
    }
    ARRAY(int *arr1){
        arr = arr1;
    }

    void operator= (const int* p)
	{	
		for(int i=0;i<n;i++)
			arr[i]=p[i];
	}

	void operator= (const ARRAY &a)
	{

		n=a.n;
		arr=new int[a.n];
		for(int i=0;i<n;i++)
			arr[i]=a.arr[i];
	}


    ARRAY operator+ (const ARRAY &c){
        ARRAY a1(c.n,0);
        for(int i =0 ; i<c.n;i++)
        a1.arr[i] = arr[i] + c.arr[i];
        return a1;
    }

    int& operator[](int i){
        return arr[i]; 
    }

    ARRAY operator *(int x)
	{
		ARRAY c(n);
		for(int i=0;i<n;i++)
			c.arr[i]=x*arr[i];
		return c;
	}
};


int main(){

    

    

    
    
    
    
    

    for(;;){
        cout<<"Enter : \n1. To create an Array object\n2. To create an Array object with another Array object\n3. To create an Array object with a primitive array\n4. To add two Array objects\n5. To multiply Array object with an integer\n6. To equate two Array objects\n7. To display all elements of an Array object using the subscript operator\n8. To exit";
        int c;
        cin>>c;
        switch(c){
            case 1:{
                int a,b;
                cout<<"Enter size and value for assignment\n";
                cin>>a>>b;
                ARRAY a1(a,b);
                cout<<"The Array is: \n";
                for(int i=0;i<a;i++)
                cout<<a1[i]<<" ";
                cout<<endl;
                break;
            }
            case 2:{
                int a,b;
                cout<<"Enter size and value for assignment of first Array object\n";
                cin>>a>>b;
                ARRAY b1(a,b);
                cout<<"The first Array object is: \n";
                for(int i=0;i<a;i++)
                cout<<b1[i]<<" ";
                cout<<endl;
                cout<<"The second copied Array object is: \n";           
                ARRAY c(a);
                c = b1;
                for(int i=0;i<a;i++)
                cout<<c[i]<<" ";
                cout<<endl;
                break;
            }
            case 3:{
                int a,b;
                cout<<"Enter size and value for assignment of primitive array\n";
                cin>>a>>b;
                int *x;
                x = new int(a); 
                for(int i=0;i<a;i++)
                x[i] = b;
                cout<<"The primitive array is: \n";
                for(int i=0;i<a;i++)
                cout<<x[i];
                cout<<endl;
                ARRAY e(x);
                cout<<"The result is: \n";
                for(int i=0;i<a;i++)
                cout<<e[i]<<" ";
                cout<<endl;
                break;
            }
            case 4:{
                int p,q;
                cout<<"Enter size and value for assignment of first Array object\n";
                cin>>p>>q;
                ARRAY d1(p,q);
                cout<<"The first Array object is: \n";
                for(int i=0;i<p;i++)
                cout<<d1[i]<<" ";
                int x,y;
                cout<<"Enter size and value for assignment of second Array object\n";
                cin>>x>>y;
                ARRAY d2(x,y);
                cout<<"The second Array object is: \n";
                for(int i=0;i<p;i++)
                cout<<d2[i]<<" ";
                if(x!=p){
                    cout<<"Array object lengths are not same, please enter same length\n";
                    break;
                }
                ARRAY d = d1+d2;
                cout<<"The added array objects result is:\n";
                for(int i=0;i<p;i++)
                cout<<d[i]<<" ";
                cout<<endl;
                break;
            }
            case 5:{
                int a,b,c;
                cout<<"Enter size and value for assignment of first Array object\n";
                cin>>a>>b;
                ARRAY b1(a,b);
                cout<<"The first Array object is: \n";
                for(int i=0;i<a;i++)
                cout<<b1[i]<<" ";
                cout<<"Enter integer to multiply object with:\n";
                cin>>c;
                ARRAY f(6);
                f = b1*c;
                cout<<"The result is: \n";
                for(int i=0;i<a;i++)
                cout<<f[i]<<" ";
                cout<<endl;
                break;
            }
            case 6:{
                int a,b;
                cout<<"Enter size and value for assignment of first Array object\n";
                cin>>a>>b;
                ARRAY b1(a,b);
                cout<<"The first Array object is: \n";
                for(int i=0;i<a;i++)
                cout<<b1[i]<<" ";
                cout<<"The equated Array object is\n";
                ARRAY c(a);
                c = b1;
                for(int i=0;i<a;i++)
                cout<<c[i]<<" ";
                cout<<endl;
                break;
            }
            case 7:{
                int a,b;
                cout<<"Enter size and value for assignment of first Array object\n";
                cin>>a>>b;
                ARRAY b1(a,b);
                cout<<"The Array object is: \n";
                for(int i=0;i<a;i++)
                cout<<b1[i]<<" ";
                break;
            }
            case 8:{
                cout<<"Exiting ... \n";
                exit(0);
                break;
            }
            default:{
                cout<<"Wrong input";
                break;
            }
        }
    }
    return 0;
}