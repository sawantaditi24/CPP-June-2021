#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

void naivePattern(string &s1, string &s2)
{
    int m = s1.length();
    int n = s2.length();

    for(int i=0; i<=m-n; i++)
    {
        int j;
        for(j=0; j<n; j++)
            if(s1[i+j]!=s2[j])
                break;

        if(j==n)
            cout<<i<<" ";
    }

}

int main()
{
    string s1, s2;

    cout<<"Enter main string to perform searching in: ";
    getline(cin, s1);
    cout<<"Enter the pattern to search: ";
    getline(cin, s2);
    naivePattern(s1, s2);
}

