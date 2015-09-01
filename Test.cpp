
#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
using namespace std;
enum PointerTag{
	Link,
	Thread
};

struct BiTNode{
	int data;
	BiTNode *lchild,*rchild;
	PointerTag lTag,rTag;
};

typedef BiTNode *BiTree;
int main()
{
	PointerTag lTag=Link;
	cout<<lTag<<endl;
	
	
	
	return 0;
}
//create binary tree
void createBiTree(BiTree &T)
{
	BiTNode node1,node2,node3,node4,node5,node6,node7;
	node1.data=1;
	node2.data=2;
	node3.data=3;
	node4.data=4;
	node5.data=5;
	node6.data=6;
	node7.data=7;
	node1.lchild=&node2;
	node1.rchild=&node3;
	node2.lchild=&node4;
	node2.rchild=nullptr;
	node3.lchild=&node5;
	node3.rchild=&node6;
	node4.lchild=nullptr;
	node4.rchild=&node7;
	node5.lchild=nullptr;
	node5.rchild=nullptr;
	node6.lchild=nullptr;
	node6.rchild=nullptr;
	node7.lchild=nullptr;
	node7.rchild=nullptr;
	T=&node1;
	//int preOrderTraverse(BiTree);
	//preOrderTraverse(T);
	int inOrderTraverse(BiTree);
	inOrderTraverse(T);
}
/*
 * preOrderTraverse
 */
int  preOrderTraverse(BiTree tree)
{
	if(tree==nullptr)
	{
		//cout<<"nullptr"<<endl;
		return 0;
	}
	
	//cout<<"sunyang"<<endl;
	//cout<<tree->lchild<<endl;
	preOrderTraverse(tree->lchild);
	
	preOrderTraverse(tree->rchild);
	cout<<tree->data<<endl;
	return 0;
}
/*
 * not use recursion
 */
int inOrderTraverse(BiTree T)
{
	stack<BiTree> conStack;
	conStack.push(T);
	while(!conStack.empty())
	{
		T=conStack.top();
		while(T)
		{
			conStack.push(T->lchild);
			T=T->lchild;
		}
		conStack.pop();
		if(!conStack.empty())
		{
			BiTree currNode=conStack.top();
			cout<<currNode->data<<endl;
			conStack.pop();
			conStack.push(currNode->rchild);
		}	
	}
	
	return 0;
}
/*
 * thread binary tree
 */
 int inorderThreadTraverse(BiTree T)
 {
	 while(T){
		 while(T->lchild)
		 {
			  T=T->lchild
	     }
	     cout<<T->data<<endl;
	     if(T->rTag==Thread)
	     {
			 T=T->rchild;
		 }else{
			 T=T->rchlid;
			 while(T->lchild)
			 {
				 T=T->lchild;
			 }
		 }
	 }
	 return 0;
 }
 /*
  * create the thread binary tree.
  */
  int createThreadBiTree(BiTree T)
  {
	  stack<BiTree> conStack;
	  
	  BiTree pre=T;
	  BiTree p=T->lchild;
	  while(p)
	  {
		  while(p->lchild) p=p->lchild;
		  p->lTag=Thread;
		  p->lchild=pre;
		  
		  
	  }
	  
	  
	  
  }
/*
 * multiply string
 */
string multiply(string num1,string num2){
	if(num1.length()==0||num2.length()==0)
	{
		return "";
	}
	//the  string have negtive symbol
	bool flag=false;
	if(num1.length()&&num1[0]=='-')
	{
		flag=!flag;
		num1=num1.substr(1);
	}
	if(num2.length()&&num2[0]=='-')
	{
		flag=!flag;
		num2=num2.substr(1);
	}
	if(num1.length()<num2.length()) swap(num1,num2);
	cout<<num1<<" "<<num2<<endl;
	string resultStr(num1.length()+num2.length(),'0');
	//cout<<resultStr<<endl;
	for(string::size_type i=num2.length();i>0;--i)
	{
		int curr1=num2[i-1]-'0';
		//cout<<"curr1  "<<curr1<<endl;
		int carry=0;
		string multiStr="";
		for(string::size_type j=num1.length();j>0;--j)
		{
			int curr2=num1[j-1]-'0';
			int multi=curr1*curr2+carry;
		    carry=multi/10;
			int first=multi%10;
			multiStr=to_string(first)+multiStr;
			//cout<<multiStr<<endl;
		}
		multiStr=to_string(carry)+multiStr;
		multiStr+=string(num2.length()-i,'0');
		cout<<"multiStr  "<<multiStr<<endl;
		carry=0;
		string::size_type j,m;
		for(j=multiStr.length(),m=resultStr.length();j>0;--j,--m)
		{
			int sum=multiStr[j-1]-'0'+resultStr[m-1]-'0'+carry;
			carry=sum/10;
			resultStr[m-1]=sum%10+'0';             //int convert to char 
		}
		resultStr[m-1]=carry+'0';             
	}
	//cout<<resultStr<<endl;
	string::size_type i;
	for(i=0;i<resultStr.length();++i)
	{
		if(resultStr[i]!='0')
		{
			break;
		}
	}
	string result=resultStr.substr(i);
	//cout<<result<<endl;
	if(result.length()==0)
	{
		result="0";
	}else{
		if(flag)
		{
			result='-'+result;
		}
	}
	
	return result;

}
/*
 * wildcard strings. problem:44
 * backtracking ???
 * 
 */
 bool isMatch(string s,string p)
 {
	 if(p.length()==0&&s.length()!=0)
	 {
		 return false;
	 }
	 if(p.length()==0&&s.length()==0)
	 {
		 return true;
	 }
	 // the string p's length is not zero.
	 char currLetter=p[0];
	 if(currLetter=='*')
	 {
		 cout<<"*"<<endl;
		 string::size_type pi=1;
		 unsigned cnt=0;
		 for(pi=1;pi<p.length();++pi)
		 {
			 if(p[pi]!='*')
			 {
				 break;
			 }
		 }
		 
		 for(string::size_type pt=pi;pt<p.length();++pt)
		 {
			 if(p[pt]!='*')
			 {
				 ++cnt;
			 } 
		 }
		 //cout<<cnt<<endl;
		 for(size_t i=0;i+cnt<=s.length();++i)
		 {
			 string currStr=s.substr(i);
			 string currPtt=p.substr(pi);
			 bool matchFlag=isMatch(currStr,currPtt);
			 if(matchFlag) return true;
		 }
		 return false;
		 
	 }else if(currLetter=='?')
	 {
		 if(s.length()==0)
		 {
			 return false;
		 }
		 string currStr=s.substr(1);
		 string currPtt=p.substr(1);
		 bool matchFlag=isMatch(currStr,currPtt);
		 if(matchFlag) return true;
		 return false;
		 
	 }else{
		 if(s.length()==0||s[0]!=currLetter)
		 {
			 return false;
		 }
		 bool matchFlag=isMatch(s.substr(1),p.substr(1));
		 if(matchFlag) return true;
		 return false; 
	 }
 }
 /*
  * amazing solution for wildcard matching.
  */
 bool misMatch(string s,string p)
 {
	 
	 return true;
		 
	 
 }
/*
 * jump gameII problem:45  f**k time limit exceeded.
 */
 int jump(vector<int>&nums)
 {
	 int cnt=INT_MAX;
	 if(nums.size()<=1)
	 {
		 return 0;
	 }
	 unsigned currnum=nums[0];
	 //cout<<currnum<<endl;
	 for(vector<int>::size_type i=1;i<=currnum;++i)
	 {
		 if(i>=nums.size())
		 {
			 continue;
		 }
		 vector<int> leftVector=nums;
		 leftVector.erase(leftVector.begin(),leftVector.begin()+i);
		 int jumpNum=1+jump(leftVector);
		 //cout<<"jumpNum  "<<jumpNum<<endl;
		 if(jumpNum!=0&&jumpNum<cnt) cnt=jumpNum;
		 //cout<<"cnt "<<cnt<<endl;
	 }
	 //cout<<"outside for"<<endl;
	 //cout<<cnt<<endl;
	 if(cnt==INT_MAX)
	 {
		 return -1;
	 }else{
		 return cnt;
	 }
 }
 /*
  * f**k,time limt exceeded too... 
  */
 int jumpII(vector<int> &nums)
 {
	 if(nums.size()<=1)
	 {
		 return 0;
	 }
	 for(vector<int>::size_type j=0;j<nums.size();++j)
	 {
		 
	 }
	 vector<int>::size_type i=nums.size();
	 int jumpCnt=0;
	 while(i>1)
	 {
		 int last=-1;
		 for(vector<int>::size_type j=i-1;j>=1;--j)
		 {
			 if(nums[j-1]+j>=i)
			 {
				 last=j;
			 }
		 }
		 i=last;
		 ++jumpCnt; 
	 }
	 return jumpCnt;
 }
 /*
  * permutations.problem:45
  */
  vector<vector<int>> permute(vector<int>&nums)
  {
	  vector<vector<int>> resultVector;
	  vector<vector<int>> rtVector;
	  if(nums.size()==1)
	  {
		  vector<int> elemVector;
		  elemVector.push_back(nums[0]);
		  resultVector.push_back(elemVector);
		  return resultVector;
	  }
	  for(vector<int>::size_type i=0;i<nums.size();++i)
	  {
		  vector<int> currVector=nums;
		  int currNum=nums[i];
		  currVector.erase(currVector.begin()+i);
		  rtVector=permute(currVector);
		  for(vector<vector<int>>::size_type j=0;j<rtVector.size();++j)
		  {
			  vector<int> insVector=rtVector[j];
			  insVector.push_back(currNum);
			  resultVector.push_back(insVector);  
		  }
	  }
	  return resultVector;
	  
	  
  }
  /*
   * permutations II. problem:46
   */
 vector<vector<int>> permuteUnique(vector<int> &nums)
 {
	 vector<vector<int>> resultVector;
	 vector<vector<int>> rtVector;
	 if(nums.size()==1)
	 {
		 vector<int> initVector;
		 initVector.push_back(nums[0]);
		 bool flag=true;
		 for(vector<vector<int>>::size_type i=0;i<resultVector.size();++i)
		 {
			 vector<int> comVector=resultVector[i];
			 bool isEqual=equal(initVector.begin(),initVector.end(),comVector.begin());
			 if(isEqual)
			 {
				 flag=false;
				 break;
			 }
		 }
		 if(flag)
		 {
			 resultVector.push_back(initVector);
		 }
		 return resultVector;
	 }
	 for(vector<int>::size_type i=0;i<nums.size();++i)
	  {
		  vector<int> currVector=nums;
		  int currNum=nums[i];
		  currVector.erase(currVector.begin()+i);
		  rtVector=permuteUnique(currVector);
		  for(vector<vector<int>>::size_type j=0;j<rtVector.size();++j)
		  {
			  vector<int> insVector=rtVector[j];
			  insVector.push_back(currNum);
			  bool flag=true;
			  for(vector<vector<int>>::size_type m=0;m<resultVector.size();++m)
			  {
				  vector<int> comVector=resultVector[m];
				  bool isEqual=equal(insVector.begin(),insVector.end(),comVector.begin());
				  if(isEqual)
				  {
					  flag=false;
					  break;
				  }
			  }
			  if(flag) resultVector.push_back(insVector);  
		  }
	  }
	 return resultVector;
	 
 }
