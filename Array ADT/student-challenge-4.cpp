#include<iostream>
using namespace std;

//program to find multiple duplicate elements in a sorted array
int main(){

    int n;
    int lastDuplicate=0, count=0;
    cout<<"Enter size of array: ";
    cin>>n;
    int A[n];
    cout<<"Enter elements in array in sorted format, duplicating 1 or more element(s): ";
    for(int i=0; i<n; i++)
        cin>>A[i];

    for(int i=0; i<n-1; i++)
    {
        if(A[i]==A[i+1] &&  lastDuplicate!=A[i])
        {
            //counting repetitions
            int j=i+1;
            while(A[j]==A[i])
               j++;

            cout<<A[i]<<" is duplicated "<<j-i<<" times.\n";
            lastDuplicate=A[i];
            //counting number of elements with duplicates
            count++;
        }
    }
    cout<<"\nTotal "<<count<<" elements had duplicates in the array.";
}
