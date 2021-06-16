#include<iostream>
using namespace std;

//program to find multiple duplicate elements in a sorted array using Hashing
int main(){

    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int A[n];
    cout<<"Enter elements in array in sorted format, duplicating 1 or more element(s): ";
    for(int i=0; i<n; i++)
        cin>>A[i];

    int Max=A[n-1];
    int H[Max+1]={0};

    for(int i=0; i<n; i++)
    {
        H[A[i]]++;
    }

    int k=0;
    while(k<=Max)
    {
        if(H[k]>1)
            cout<<k<<" is duplicated "<<H[k]<<" times.\n";
        k++;
    }
}
