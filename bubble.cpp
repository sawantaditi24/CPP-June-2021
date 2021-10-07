#include<iostream>
using namespace std;

int main()
{								//BUBBLE SORT
	int n,arr[10],pass;
	cout<<"Enter the number of elements:";
	cin>>n;
	cout<<"Enter the elements of the array:";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[i])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				
			}
		}
		pass++;
	
	}
	cout<<"The sorted elements of the array are:";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"\nThe number of passes required to sort the array are:"<<pass<<endl;
	
	return 0;
	



}

