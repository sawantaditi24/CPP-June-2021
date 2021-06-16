#include<iostream>
using namespace std;

//program to find pair of elements with a particular sum in unsorted array using hash array O(n)
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

    int Max=A[0];
    for(int i=0; i<n; i++)
    {
        if(A[i]>Max)
            Max=A[i];
    }

    int H[Max]={0};
    for(int i=0; i<n; i++)
     {
         if(H[sum-A[i]]>0)
         {
             cout<<"The pair is: ("<<A[i]<<","<<sum-A[i]<<")\n";
             count++;
         }
         H[A[i]]++;
     }
     cout<<"Total number of pairs: "<<count;
}


