//Create an array of student objects (containing roll, name, name and score)
//whose size may vary dynamically once objects are added or removed, randomly
//elements may be accessed, one can find number of objects in the list, one can
//find the student with highest score, find the students with a substring in their
//name and also without a substring in the name. Take the help of suitable STL
//classes.


#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Student{
    public:
    int roll,score;
    string name;
    Student(){
        cout<<"Enter roll, name, score:\n";
        cin>>roll>>name>>score;
    }
    void show(){
        cout<<"Roll : "<<roll<<" Name : "<<name<<" Score : "<<score<<endl;
    }
};

void highScore(vector<Student> arr){
    int max=-10000;
    for(auto it = arr.begin();it!=arr.end();++it)
        if(it->score>max)
            max = it->score;
    for(auto it = arr.begin();it!=arr.end();++it)
        if(it->score==max)
            it->show();

}

bool checkString(string s1,string s2){
    int M = s1.length();
    int N = s2.length();
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
        if (j == M)
            return true;
    }
    return false;
}

void findString(vector<Student> arr,string s){
    for(auto i = arr.begin();i!= arr.end();++i){
        if(checkString(s,i->name))
        i->show();
    }
}

void notString(vector<Student> arr,string s){
    for(auto i = arr.begin();i!= arr.end();++i){
        if(!checkString(s,i->name))
        i->show();
    }
}

int main(){
    vector<Student> arr;
    for(;;){
        cout<<"Enter : \n1. To add a student\n2. To access student by index \n3. To find student with max score \n4. To find number of students\n5. To find student with a substring present in name\n6. To find student without substring present in name\n7. To remove last added student\n8. To show all students\n9. To exit\n";
        int c;
        cin>>c;
        switch(c){
            case 1:{
                Student temp;
                arr.push_back(temp);
                break;
            }
            case 2:{
                cout<<"Enter index :\n";
                int index;
                cin>>index;
                arr[index].show();
                break;
            }
            case 3:{
                highScore(arr);
                break;
            }
            case 4:{
                cout<<"The number of students is : "<<arr.size()<<endl;
                break;
            }
            case 5:{
                string x;
                cout<<"Enter string to check:\n";
                cin>>x;
                cout<<"The students are:\n";
                findString(arr,x);
                break;
            }
            case 6:{
                string x;
                cout<<"Enter string to check:\n";
                cin>>x;
                cout<<"The students are:\n";
                notString(arr,x);
                break;
            }
            case 7:{
                arr.pop_back();
                cout<<"Removed\n";
                break;
            }
            case 8:{
                for(auto it = arr.begin();it!=arr.end();++it)
                it->show();
                break;
            }
            case 9:{
                cout<<"Exiting...\n";
                exit(0);
                break;
            }
            default:{

                break;
            }
        }
    }
    

    return 0;
}