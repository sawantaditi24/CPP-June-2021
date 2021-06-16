#include<iostream>
using namespace std;

//program to find multiple missing elements in an unsorted linear array
int main(){

    int n, l, h;
    int d=0;
    cout<<"Enter size of array: ";
    cin>>n;
    int A[n];
    cout<<"Enter elements in array in linear unsorted format, leaving 1 or more element(s) missing: ";
    for(int i=0; i<n; i++)
        cin>>A[i];

    //finding max element
    int Max=A[0];
    for(int i=0; i<n; i++)
    {
        if(A[i]>Max)
            Max=A[i];
    }
    cout<<"Max is: "<<Max<<endl;

    //finding min element
    int Min=A[0];
    for(int i=0; i<n; i++)
    {
        if(A[i]<Min)
            Min=A[i];
    }
    cout<<"Min is: "<<Min<<endl;

    //Making hash array
    int H[Max+1]={0};
    cout<<"Hash Array: ";
    for(int i=0; i<=Max; i++)
        cout<<H[i]<<" ";

    //incrementing hash table with index as key
    for(int i=0; i<n; i++)
    {
        H[A[i]]++;
    }

    //printing missing elements
    for(int i=Min; i<=Max; i++)
    {
        if(H[i]==0)
            cout<<endl<<i<<" is missing.";
    }

}
