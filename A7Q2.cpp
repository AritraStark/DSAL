// Create an array of student objects where along with the support mentioned in
// Q.1, one can remove an object with specific roll, sort the collection in the
// descending order and show the same; two student collections can also be
// combined. Take the help of suitable STL class.

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

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

void removeEl(vector<Student> arr,int x){
    for(auto i = arr.begin();i!= arr.end();++i){
        if(i->roll == x){
            arr.erase(i);
            return;
        }
    }
    cout<<"Roll not found\n";
}

bool compareEl(Student a,Student b){
    if(a.score != b.score)
    return (a.score > b.score);
}

void sortEl(vector<Student> arr){
    sort(arr.begin(),arr.end(),compareEl);
    cout<<"Sorted\n";
    for(auto it = arr.begin();it!=arr.end();++it)
        it->show();
}

int main(){
    vector<Student> arr;
    for(;;){
        cout<<"Enter : \n1. To add a student\n2. To access student by index \n3. To find student with max score \n4. To find number of students\n5. To find student with a substring present in name\n6. To find student without substring present in name\n7. To remove last added student\n8. To show all students\n9. To remove a student\n10. To sort in descending order of score\n11. To exit\n";
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
                cout<<"Enter Roll to remove:\n";
                int x;
                cin>>x;
                removeEl(arr,x);
                break;
            }
            case 10:{
                sortEl(arr);
                break;
            }
            case 11:{
                cout<<"Exiting...\n";
                exit(0);
                break;
            }
            default:{
                cout<<"Wrong input\n";
                break;
            }
        }
    }
    

    return 0;
}