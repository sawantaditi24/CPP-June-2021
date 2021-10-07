// CPP program to perform Linear Search effectively
#include<iostream>
using namespace std;

int main()
{
	int n,a[10],flag=0,key;
	cout<<"Enter the element to be searched:";
	cin>>key;
	cout<<"Enter the number of elements present:";
	cin>>n;
	cout<<"Enter the elements of the array:";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
	cout<<"Searching element in the array..."<<endl;
	for(int i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			flag=1;
			cout<<"Entered element is found at position "<<i+1;
		}
	}
	if(flag==1)
	{
		//cout<<"Element found."<<endl;
	}
	else
	{
		cout<<"Entered element not present."<<endl;
	}
}
