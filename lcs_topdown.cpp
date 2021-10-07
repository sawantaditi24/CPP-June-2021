//Longest Common Subsequence ------ Top Down Approach

#include<bits/stdc++.h>
using namespace std;
int t[1002][1002];
int lcs(string x,string y,int m,int n)
{	 
	
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0||j==0)
			{
				t[i][j] = 0;
			}
		}
	}
	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(x[i-1]==y[j-1])
			{
				return t[i][j] = 1+t[i-1][j-1];
			}
			else
			{
				return t[i][j] = max(t[i-1][j],t[i][j-1]);
			}	
		}
	
	}
	
	return t[m][n];
	
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
