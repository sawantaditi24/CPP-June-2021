#include<iostream>
using namespace std;

//program to find multiple missing elements in sorted linear array
int main(){

    int n;
    int d=0;
    cout<<"Enter size of array: ";
    cin>>n;
    int A[n];
    cout<<"Enter elements in array in linear sorted format, leaving 1 or more element(s) missing: ";
    for(int i=0; i<n; i++)
        cin>>A[i];

    d=A[0]-0;
    for(int j=0; j<n; j++)
    {
        while(A[j]-j!=d)
        {
            cout<<j+d<<" was missing."<<endl;
            d++;
        }
    }
}
