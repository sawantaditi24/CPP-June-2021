#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
void rev(char Str[], int low, int high)
{
    while(low<high)
    {
        swap(Str[low], Str[high]);
        low++;
        high--;
    }
}


void wordRev(char str[], int n)
{
    int start = 0;
    for(int End=0; End<n; End++)
        if(str[End] == ' ')
        {
            rev(str, start, End-1); // reversing individual words internally
            start = End+1;
        }

    rev(str, start, n-1); // reversing last word separately
    rev(str, 0, n-1); // reversing whole string in the end
}

int main()
{
    string s;
    cout<<"Enter string to reverse its words: ";
    getline(cin, s);
    int n=s.length();
    char str[n];
    strcpy(str, s.c_str());  //s.c_str() converts string to char array/c string

    wordRev(str, n);
    cout<<"String after reversing: ";
    for(int i=0; i<n; i++)
        cout<<str[i];
}
