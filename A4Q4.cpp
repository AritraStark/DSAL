#include <iostream>

using namespace std;

class STRING{
	int sz;
	char *data;
	public:
		//constructor 
		STRING(int l=0, char c='\0'){
			if(l>0){
				sz=l;
				data=new char[sz+1];
				data[sz]='\0';
				for(int i=0;i<l;i++)
					data[i]=c;
			}
			else{
				sz=0;
				data=NULL;
			}
		}

		//copy constructor
		STRING(const STRING& s){
			sz=s.sz;
			if(sz==0)
				data=NULL;
			else{
				//delete data;
				data=new char[sz+1];
				data[sz]='\0';
				for(int i=0;i<sz;i++)
					data[i]=s.data[i];
			}
			
		}

		//assignment operator
		void operator =(const STRING& s){
			if(sz!=0)
			delete data;
			sz=s.sz;
			if(sz==0)
				data=NULL;
			else{
				data=new char[sz+1];
				data[sz]='\0';
				for(int i=0;i<sz;i++)
					data[i]=s.data[i];
			}

		}

		//concatenation
		STRING operator +(const STRING& s){
			STRING res;
			res.sz=sz+s.sz;
			res.data=new char[res.sz+1];

			for(int i=0;i<sz;i++)
				res.data[i]=data[i];

			for(int i=0;i<s.sz;i++)
				res.data[sz+i]=s.data[i];
			res.data[res.sz]='\0';


			return res;
		}

		//comparing 
		bool operator ==(const STRING& s){
			if(sz!=s.sz)
				return false;
 
			if(sz==0 && s.sz==0)
				return true;

			for(int i=0;i<sz;i++){
				if(data[i]!=s.data[i])
					return false;
			}
			return true;
		}

		//< relational operator
		bool operator <(const STRING& s){
			if(sz==0 && s.sz==0)
				return false;

			int min=(sz<s.sz)?sz:s.sz;
			for(int i=0;i<min;i++){
				if(data[i]<s.data[i])
					return true;

				else if(data[i]>s.data[i])
					return false;
			}

			if(sz==s.sz)
				return false; //both are identical
			if(sz<s.sz)
				return true; //first string has fewer characters
			if(sz>s.sz)
				return false; // first string has more characters
		}

		//> relational operator
		bool operator >(const STRING& s){
			if(sz==0 && s.sz==0)
				return false;

			int min=(sz<s.sz)?sz:s.sz;
			for(int i=0;i>min;i++){
				if(data[i]>s.data[i])
					return true;

				else if(data[i]<s.data[i])
					return false;
			}
			//if all prev characters are equal
			if(sz==s.sz)
				return false; //identical
			if(sz>s.sz)
				return true; // first string has more characters 
			if(sz<s.sz)
				return false; // first string has less characters
		}

		friend istream& operator >>(istream &in, STRING &s);
		friend ostream& operator <<(ostream &o, STRING const &s);

		//destructor
		~STRING(){
			if(data!=NULL)
				delete data;
		}
};

//for taking string as input
istream& operator >>(istream& in, STRING& s){
	char ch;
	cout<<"Enter length of string : ";
	in>>s.sz;
	char* data=new char[s.sz+1];
	data[s.sz]='\0';
	cout<<"Enter string : ";
	for(int i=0;i<s.sz;i++){
		cin>>ch;
		data[i]=ch;
	}
	s.data=data;
	return in;
}
 

//for displaying string
ostream& operator <<(ostream &o, STRING const &s){
	for(int i=0;i<s.sz;i++)
		cout<<s.data[i];
	return o;
}


int main(){
	STRING s1, s2, s3;
	int ch,c;
	char s;
	do{
		cout<<"\nEnter :\n1. Add two strings\n2. Compare two strings\n3. Copy of a string\n4. Exit\n\n";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter string 1\n";
				cin>>s1;
				cout<<"Enter string 2\n";
				cin>>s2;
				s3=s1+s2;
                                cout<<"\n Result :\n";
				cout<<s1<<" + "<<s2<<" = "<<s3<<"\n";
				break;
			case 2:
				cout<<"Enter first string\n";
				cin>>s1;
				cout<<"Enter second string\n";
				cin>>s2;
				do{
					cout<<"\t1. <\n";
					cout<<"\t2. ==\n";
					cout<<"\t3. >\n";
					cout<<"\t\tEnter choice:";
					cin>>c; 
					switch(c){
						case 1: //s1 less than s2 checking
							cout<<s1<<" < "<<s2<<" = "<<(s1<s2)<<"\n";
							break;
						case 2: //Equality
							cout<<s1<<" == "<<s2<<" = "<<(s1==s2)<<"\n";
							break;
						case 3://s1 greater than s2 checking
							cout<<s1<<" > "<<s2<<" = "<<(s1>s2)<<"\n";
							break;
						default://wrong checking
							cout<<"Wrong choice. Enter again!\n";
							s='y';
							continue;
					}
					cout<<"Do you want to continue with the same strings? Enter F to change strings, N to stop comparing, and any other key to continue :\n";
					cin>>s;
					if(s=='f' || s=='F'){
						cout<<"Which string do you want to change? 1 or 2\n";
						do{
							cin>>c;
							if(c==1){
								cout<<"Enter string 1\n";
								cin>>s1;
							}
							else if(c==2){
								cout<<"Enter string 2\n";
								cin>>s2;	
							}
							else{
								cout<<"Wrong choice...Enter again\n";
							}
						}while(c!=1 && c!=2);
					}
				}while(s!='n' && s!='N');
				break;
			case 3:
				cout<<"Displaying value of string 1 at this moment : "<<s1
				    <<"\nEnter string to copy : \n";
				cin>>s2;
				cout<<"Displaying value of string s2 : "<<s2<<endl;
				s1=s2;
				cout<<"Displaying new value of string 1 : "<<s1<<endl;
				break;
			case 4:
				cout<<"Exiting ... ";
				break;
			default:
				cout<<"Wrong input\n";
		}
	}while(ch!=4);
}