#include<iostream>
using namespace std;

//program to find max and min in an unsorted array simultaneously O(n sq.)
int main(){

    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int A[n];
    cout<<"Enter elements in array without duplication : ";
    for(int i=0; i<n; i++)
        cin>>A[i];

    int Max = A[0];
    int Min = A[0];
    for(int i=0; i<n; i++)
    {
        if(A[i]>Max)
            Max=A[i];
        else if(A[i]<Min)
            Min=A[i];
    }
    cout<<"Max value is: "<<Max<<endl;
    cout<<"Min value is: "<<Min;
}

