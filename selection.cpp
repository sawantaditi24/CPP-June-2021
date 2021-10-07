//CPP program to perform selection sort(complexity: O(n^2))

#include<iostream>
using namespace std;

int main()
{
	int n,arr[10],loc,min;
	cout<<"Enter the number of elements present:";
	cin>>n;
	cout<<"Enter the elements to be sorted:";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	for(int i=0;i<n-1;i++)
	{
		min = arr[i];
		loc = i;
		
		for(int j=i+1;j<n;j++)
		{
			if(min>arr[j])
			{
				min = arr[j];
				loc = j;
			}
		
		}
		int temp = arr[i];
		arr[i] = arr[loc];
		arr[loc] = temp;
	
	}
	
	cout<<"The sorted elements are:";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i];
	}
	
	return 0;


}
