#include<iostream>
using namespace std;

//program to find pair of elements with a particular sum in unsorted array O(n)
int main(){

    int n;
    int sum, count=0;
    cout<<"Enter size of array: ";
    cin>>n;
    int A[n];
    cout<<"Enter elements in sorted manner in array without duplication : ";
    for(int i=0; i<n; i++)
        cin>>A[i];

    cout<<"\nEnter the sum value you want to find additive pair for: ";
    cin>>sum;
    cout<<endl;

    int i=0, j=n-1;
    while(i!=j)
    {
        if(A[i]+A[j]>sum)
            j--;
        else if(A[i]+A[j]<sum)
            i++;
        else
        {
            cout<<"The pair is: ("<<A[i]<<","<<A[j]<<")\n";
            i++;
            j++;
        }
    }
}
