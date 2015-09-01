#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<utility>
#include<iterator>

using namespace std;
/*
 * This file is a implementation of Graph algorithms of introduction to algorithms.
 * 08-27-2015 
 * 
 */
 #define VEXSIZE 5
 enum color{
	 white,
	 gray,
	 black
	 
 };
 struct GraphNode{
	 int data;
	 color visitFlag;
	 int d;
	 GraphNode *parent;
 };
 struct VNode{
	 GraphNode* dataPt;
	 VNode *next;
 };
 class firend2;
 class firend1{
	 friend void firend2::method();
	 string name="sunyang";
	 
 };
 class firend2{
	 void method()
	 {
		 firend1 instan;
		 cout<<instan.name<<endl;
	 }
 };
 
 typedef VNode ajList[VEXSIZE];
int main()
{
	/*GraphNode nodeArray[5];
	ajList listArray;
	for(size_t i=0;i<5;++i)
	{
		nodeArray[i].data=i+1;
		
	}
	for(size_t i=0;i<VEXSIZE;++i)
	{
		listArray[i].dataPt=&nodeArray[i];
	}
	string line;
	int index=0;
	while(getline(cin,line))
	{
		VNode *pre=&listArray[index];
		stringsteam ss(line);
		char delim=' ';
		string item;
		vector<int> nodeNums;
		while(geline(ss,item,delim))
		{
			int num=stoi(item);
			nodeNums.push_back(num);
		}
		for(vector<int>::size_type i=0;i<nodeNums.size();++i)
		{
			VNode 
			
			
			
			
		}
		
		
		
		
		
	}*/
	firend2 instan;
	instan.method();
	
	
	
	return 0;
}
/*
 * rotate image problem:48
 */
 void rotate(vector<vector<int>> &matrix)
 {
	 int n=matrix.size();
	 for(int i=0;i<n;++i)
	 {
		 for(int j=0;j<i;++j)
		 {
			 swap(matrix[i][j],matrix[j][i]);
		 }
	 }
	 for(int i=0;i<n;++i)
	 {
		 for(int j=0;j<=n/2-1;++j)
		 {
			 swap(matrix[i][j],matrix[i][n-j-1]);
		 }
	 }
	 
 }

