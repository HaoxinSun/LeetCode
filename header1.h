#include<iostream>
#include<string>
using namespace std;
class header1{
	public:
	    string name;
	    int age;
	    static string gender;
		header1():name("sunyang"),age(10){};
		header1(string name,int age):name("direct"),age(age){};
		header1(const header1 & i);
	    const header1& method()const{
			cout<<"reference to const"<<endl;
			domethod();
			return *this;
		};
	    header1 &method()
	    {
			cout<<" reference to nonconst"<<endl;
			domethod();
			return *this;
		} 
	private:
		void domethod()const{ cout<<"do method";};
		
	    
};

