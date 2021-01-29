#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class Student{
    public:
    int roll;
    string name;
    bool pass;
    
    Student(){
        roll = 0;
        name = "";
        pass = false;
    }
    Student(const Student &a){
        this->name = a.name;
        this->roll = a.roll;
        this->pass = a.pass;
    }
    // friend ostream &operator<<(ostream &output, const Student &temp){
    //     output<<"Roll: "<<temp.roll<<"| Name: "<<temp.name<<"| Pass: "<<temp.pass<<endl;
    //     return output;
    // }
    friend ostream &operator<<(ostream &output, const Student &temp){
        output<<temp.roll<<temp.name<<temp.pass;
        return output;
    }
    // friend istream &operator>>(istream &input, Student &temp){
    //     input>>temp.roll>>temp.name;
    //     return input;
    // }
    Student operator+(const Student &a){
        Student temp;
        temp.name = this->name + a.name;
        temp.roll = this->roll + a.roll;
        temp.pass = this->pass + a.pass;
        return temp;
    }
    void getter(){
        cin>>this->roll>>this->name;
    }
};




int main(){
    Student arr[5],arr2[5];
    fstream fio;
    fio.open("p1a.dat",ios::out|ios::app|ios::binary);
    for(int i = 0 ; i < 5 ; i++){
        arr[i].getter();
        fio.write((char*)&arr[i],sizeof(arr[i]));
    }
    fio.close();

    fio.open("p1a.dat",ios::in|ios::binary);
    for(int i=0;i<5;i++)
    fio.read((char *) &arr2[i], sizeof(arr2[i]));
    fio.close();
    for(int i=0;i<5;i++)
    cout<<arr2[i]<<endl<<endl;
    Student arr3[5];
    for(int i=0;i<5;i++)
    arr3[i] = arr[i] + arr2[i];
    for(int i=0;i<5;i++)
    cout<<arr3[i]<<endl;

    // Student a,b,c;
    // fstream fio;
    // fio.open("p1a.dat",ios::in|ios::binary);
    // fio.read((char *) &a, sizeof(a));
    // fio.read((char *) &b, sizeof(b));
    // c = a + b;
    // cout<<a<<endl<<b<<endl<<c;
    return 0;
}