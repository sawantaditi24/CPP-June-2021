//CPP program to perform Insertion Sort(Time Complexity: O(n^2))

#include<iostream>
using namespace std;
int main()
{
	int n,arr[10];
	cout<<"Enter the number of elements:";
	cin>>n;
	
	cout<<"Enter the elements of the array:";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	for(int k=1;k<n;k++)
	{
		int temp = arr[k];
		int j = k-1;
		while(j>=0&&temp<=arr[j])
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
	
	cout<<"Sorted elements of the array are:";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	}
	
	return 0;
	


}



