 #include<iostream>
 #include<string>
 #include"header1.h"
 
 using namespace std;
header1::header1(const header1 & i):name("copy"),age(i.age)
{
	
	
}
string header1::gender="female";
