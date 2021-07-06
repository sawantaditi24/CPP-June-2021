#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

//uses O(n) space and time

bool rotationCheck(string &s1, string &s2)
{
    if(s1.length()!= s2.length())return false;
    return((s1+s1).find(s2)!= string::npos); //concatenating s1 with itself and searching for s2 in it, string::npos is returned by find fn if fails
}

int main()
{
    string s1, s2;
    cout<<"Enter main string to perform searching in: ";
    getline(cin, s1);
    cout<<"Enter the pattern to search: ";
    getline(cin, s2);

    if(rotationCheck(s1, s2))
        cout<<"Yes, it is a rotation.";
    else
        cout<<"Not a rotation.";
}


