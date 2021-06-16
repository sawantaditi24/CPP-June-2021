#include<iostream>
using namespace std;

//program to find pair of elements with a particular sum in unsorted array O(n sq.)
int main(){

    int n;
    int sum, count=0;
    cout<<"Enter size of array: ";
    cin>>n;
    int A[n];
    cout<<"Enter elements in array without duplication : ";
    for(int i=0; i<n; i++)
        cin>>A[i];

    cout<<"\nEnter the sum value you want to find additive pair for: ";
    cin>>sum;
    cout<<endl;

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(A[i]+A[j]==sum)
            {
                cout<<"The pair is: ("<<A[i]<<","<<A[j]<<")\n";
                count++;
            }
        }
    }
    cout<<"Total number of pairs: "<<count;
}


