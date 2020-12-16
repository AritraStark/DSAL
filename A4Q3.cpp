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
    ARRAY(int n=0,int x=0){
        arr = new int(n);
        for(int i=0;i<n;i++)
        arr[i]=x;
    }
    ARRAY(const ARRAY &a){
        // n=a.n;
        // arr = new int(n);
        for(int i=0;i<a.n;i++)
        arr[i] = a.arr[i];
    }
    ARRAY(int arr1[],int n1){
        n = n1;
        //arr = new int(n1);
        for(int i=0;i<n+3;i++)
        arr[i]=arr1[i];
        //arr=arr1;
    }
    ARRAY operator+(const ARRAY &c){
        ARRAY a1(c.n+5,0);
        for(int i =0 ; i<c.n+5;i++)
        a1.arr[i] = arr[i] + c.arr[i];
        return a1;
    }
    // ARRAY operator= (ARRAY const &c){
    //     for(int i =0;i<c.n;i++)
    //     arr[i] = c.arr[i];
    // }
    int& operator[](int i){
        // if (i > n) { 
        //     ; 
        // } 
        return arr[i]; 
    }
    friend ARRAY operator*(ARRAY , int );
};

ARRAY operator* (ARRAY a, int x){
        for(int i =0;i<a.n;i++)
        a.arr[i]*=x;
    }

int main(){
    ARRAY a(6,10);
    for(int i=0;i<6;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    
    ARRAY b(6,5);
    for(int i=0;i<6;i++)
    cout<<b[i]<<" ";
    cout<<endl;

    
    ARRAY c(6);
    c = b;
    for(int i=0;i<6;i++)
    cout<<c[i]<<" ";
    cout<<endl;
    
    ARRAY d = b+a;
    for(int i=0;i<6;i++)
    cout<<d[i]<<" ";
    cout<<endl;
    
    ARRAY f(6);
    f = a*5;
    for(int i=0;i<6;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    
    int x[6];
    for(int i=0;i<6;i++)
    x[i] = 4;
    ARRAY e = ARRAY(x,10);
    for(int i=0;i<6;i++)
    cout<<e[i]<<" ";
    cout<<endl;
    
    return 0;
}