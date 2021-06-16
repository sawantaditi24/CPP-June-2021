#include<iostream>
using namespace std;

//program to find single missing element in sorted linear array
int main(){

    int n;
    int d=0;
    cout<<"Enter size of array: ";
    cin>>n;
    int A[n];
    cout<<"Enter elements in array in linear sorted format, leaving 1 element missing: ";
    for(int i=0; i<n; i++)
        cin>>A[i];

    d=A[0]-0;
    for(int j=0; j<n; j++)
    {
        if(A[j]-j!=d)
        {
            cout<<j+d<<" is missing element.";
            d++;
        }
    }
}
