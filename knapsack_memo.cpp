//Program to solve knapsack problem statement using memorization

#include<iostream>
#include<math.h>
using namespace std;

int knapsack(int wt[],int val[],int W,int n)
{
	static int t[102][1002];
 	//memset(t,-1,sizeof(t));
	if(n==0||W==0)
	{
		return 0;
	}
	if(wt[n-1]<=W)
	{
		t[n][W] = return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
	}
	else if
	{
		t[n][W] = return knapsack(wt,val,W,n-1);
	}



}
 int main()
 {
 	static int t[102][1002];
 	memset(t,-1,sizeof(t));
 	int val[100],wt[1000],n,W;
 	
 	cout<<"----KNAPSACK MEMORIZATION PROBLEM----";
 	cout<<"Enter the capacity of the knapsack bag:";
 	cin>>W;
 	cout<<"Enter the elements to be stored in the knapsack bag";
 	cin>>n;
 	cout<<"Enter the weights of the elements:";
 	for(int i=0;i<n;i++)
 	{
 		cin>>wt[i];
 	}
 	cout<<"Enter the values of the elements:";
 	for(int i=0;i<n;i++)
 	{
 		cin>>val[i];
 	}
 	knapsack(wt,val,W,n);
 	
 	
 
 }
