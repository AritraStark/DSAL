#include <iostream>

using namespace std;

class STRINGT{
	int sz;
	int* refer;
	char *data;
	public:
		//constructor 
		STRINGT(int l=0, char c='\0'){
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
			refer=new int;
			*refer=1;
			cout<<"refererence to memory block (cons ):"<<refer<<"="<<*refer<<endl;
		}

		//copy constructor
		STRINGT(const STRINGT& s){
			data=s.data;
			sz=s.sz;
			refer=s.refer;
			*refer=*refer+1;
			cout<<"Reference to the memory block (copy constructor ):"<<refer<<"="<<*refer<<endl;
		}

		//assignment operator
		void operator =(const STRINGT& s){
			data=s.data;
			sz=s.sz;
			refer=s.refer;
			*refer=*refer+1;
			cout<<"Reference to the memory block :"<<refer<<"="<<*refer<<endl;
		}

		//concatenation
		STRINGT operator +(const STRINGT& s){
			STRINGT res;
			res.sz=sz+s.sz;
			res.data=new char[res.sz+1];
			for(int i=0;i<sz;i++)
				res.data[i]=data[i];
			for(int i=0;i<s.sz;i++)
				res.data[sz+i]=s.data[i];
			res.data[res.sz]='\0';
			cout<<res.data<<endl;
			return res;
		}

		//comparing
		bool operator ==(const STRINGT& s){
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
		bool operator <(const STRINGT& s){
			if(sz==0 && s.sz==0)
				return false;
			int min=(sz<s.sz)?sz:s.sz;
			for(int i=0;i<min;i++){
				if(data[i]<s.data[i])
					return true;
				else if(data[i]>s.data[i])
					return false;
			}
			//if all prev characters are equal
			if(sz==s.sz)
				return false; //both are identical
			if(sz<s.sz)
				return true; //first string has less characters
			if(sz>s.sz)
				return false; ////first string has more characters so str1>str2
		}

		//> relational operator
		bool operator >(const STRINGT& s){
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
				return false; //both are identical
			if(sz>s.sz)
				return true; //first string has more characters 
			if(sz<s.sz)
				return false; ////first string has less characters
		}

		friend istream& operator >>(istream &in, STRINGT &s);
		friend ostream& operator <<(ostream &o, STRINGT const &s);

		//destructor
		~STRINGT(){
			*refer=*refer-1;
			cout<<"Reference to the memory block (Destructor ):"<<refer<<"="<<*refer<<endl;
			if(*refer==0){
				if(sz!=0)
					delete data;
			}
		}
};

//for taking string as input
istream& operator >>(istream& in, STRINGT& s){
	cout<<"Enter length of string : ";
	in>>s.sz;
	char* data=new char[s.sz+1];
	data[s.sz]='\0';
	cout<<"Enter string : ";
	for(int i=0;i<s.sz;i++){
		cin>>data[i];
	}
	s.data=data;
	cout<<s.data<<endl;
	return in;
}
 

//for displaying string
ostream& operator <<(ostream &o, STRINGT const &s){
	for(int i=0;i<s.sz;i++)
		cout<<s.data[i];
	return o;
}


int main(){
	STRINGT s1, s2, s3;
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
				cout<<s1<<" + "<<s2<<" = "<<s3<<"\n";
				break;
			case 2:
				cout<<"Enter first string\n";
				cin>>s1;
				cout<<"Enter second string\n";
				cin>>s2;
				do{
					cout<<"1. <\n";
					cout<<"2. ==\n";
					cout<<"3. >\n";
					cout<<"Enter choice\n";
					cin>>c;
					switch(c){
						case 1:
							cout<<s1<<" < "<<s2<<" = "<<(s1<s2)<<"\n";
							break;
						case 2:
							cout<<s1<<" == "<<s2<<" = "<<(s1==s2)<<"\n";
							break;
						case 3:
							cout<<s1<<" > "<<s2<<" = "<<(s1>s2)<<"\n";
							break;
						default:
							cout<<"Wrong choice. Enter again!\n";
							s='y';
							continue;
					}
					cout<<"Do you want to continue with the same strings? Press F to change strings, N to stop comparing, and any other key to continue\n";
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
								cout<<"Wrong input\n";
							}
						}while(c!=1 && c!=2);
					}
				}while(s!='n' && s!='N');
				break;
			case 3:
				cout<<"Displaying value of string 1  : "<<s1<<"\nEnter string to copy : \n";
				cin>>s2;
				cout<<"Displaying value of string s2 : "<<s2<<endl;
				s1=s2;
				cout<<"Displaying new value of string 1 : "<<s1<<endl;
				break;
			case 4:
				cout<<"Exiting\n";
				break;
			default:
				cout<<"Wrong input\n";
		}
	}while(ch!=4);
}