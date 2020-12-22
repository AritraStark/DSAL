#include<iostream>
using namespace std;

class ARRAY{
    private:
    int *arr;
    int size;
    public:
    ARRAY(int n){
        size = n;
        arr = new int[n];
        for(int i=0;i<n;i++){
            cout<<"Enter element "<<i+1<<" : \n";
            cin>>arr[i];
        }
    }
    int& operator[](int i){
        return arr[i];
    }
    int max(){
        int max=0;
        for(int i=0;i<size;i++){
            if(arr[i]>max)
            max=arr[i];
        }
        return max;
    }
    int sum(){
        int sum = 0;
        for(int i=0;i<size;i++)
        sum+=arr[i];
        return sum;
    }
};

int main(){
    for(;;){
        strt:
        cout<<"Enter :\n1. For new Array and operations\n2. To Exit\n";
        int c1,c2;
        cin>>c1;
        switch(c1){
            case 1:{
                cout<<"Enter length of new Array:\n";
                int x;
                cin>>x;
                ARRAY t(x);
                for(;;){
                    cout<<"Enter :\n2. For getting i'th element\n3. For getting sum of array\n4. For getting max of array\n5. To go back to main menu\n";
                    cin>>c2;
                    switch(c2){
                        case 2:{
                            cout<<"Enter index:\n";
                            int y;
                            cin>>y;
                            if(y>x||y<0){
                                cout<<"Out of bounds, invalid position\n";
                                break;
                            }
                            else{
                                cout<<"The "<<y<<"'th element is : "<<t[y]<<endl;
                                break;
                            }
                        }
                        case 3:{
                            cout<<"The sum of array is: "<<t.sum()<<endl;
                            break;
                        }
                        case 4:{
                            cout<<"The max element of array is: "<<t.max()<<endl;
                            break;
                        }
                        case 5:{
                            goto strt;
                        }
                        default:{
                            cout<<"Wrong Input";
                            break;
                        }
                    }
                }
                
                break;
            }
            case 2:{
                cout<<"Exiting ... ";
                exit(0);
            }
            default:{
                cout<<"Wrong Input";
                break;
            }
        }
    }
    return 0;
}