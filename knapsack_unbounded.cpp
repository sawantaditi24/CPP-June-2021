#include<bits/stdc++.h>
using namespace std;
int static t[102][1002];

int knapsack(int wt[],int val[],int W,int n)
{
	int t[n][W];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<W+1;j++)
		{
			if(i==0||j==0)
			{
				t[i][j]=0;
			}
		}
	}
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<W+1;j++)
		{
			if(wt[i-1]<=j)
			{
				t[i][j] = max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
			}
			else
			{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][W];
}

int main()
{
	int W,n,profit;
	
	cout<<"Enter the number of elements:";
	cin>>n;
	cout<<"Enter the maximum capacity of the knapsack bag:";
	cin>>W;
	int wt[n],val[n];
	cout<<"Enter the weight of knapsack elements:";
	for(int i=0;i<n;i++)
	{
		cin>>wt[i];
	}
	cout<<"Enter the values of the knapsack elements:";
	for(int i=0;i<n;i++)
	{
		cin>>val[i];
	}
	profit = knapsack(wt,val,W,n);
	cout<<"The maximum profit is:"<<profit;
	
	//return 0;
	
}

