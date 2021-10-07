//Longest Common Subsequence-----Memorization Approach

#include<bits/stdc++.h>
using namespace std;
static int t[m+1][n+1];
int lcs(string x,string y,int m,int n)
{
	memset(-1,t,sizeof(t));
	if(m==0||n==0)
	{
		return t[m][n];
	}
	if(x[m-1]==y[n-1])
	{
		return 1+lcs(x,y,m-1,n-1);
	}
	else
	{
		return max(lcs(x,y,m-1,n),lcs(x,y,m,n-1));
	}
}


int main()
{
	string x,y;
	int m,n,count;
	
	cout<<"Enter the first string:";
	cin.ignore();
	getline(cin,x);
	cout<<"Enter the second string:";
	cin.ignore();
	getline(cin,y);
	m = x.size()+1;
	cout<<"Length of string 1:"<<m<<endl;
	n = y.size()+1;
	cout<<"Length of string 2:"<<n<<endl;
	
	
	count = lcs(x,y,m,n);
	cout<<"The length of longest common subsequence is:"<<count;
	
	return 0;
}
