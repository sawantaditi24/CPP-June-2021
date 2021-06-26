#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;


void wordReverse(string &S)
{
    int start=0;
    for(int End=0; End<S.length(); End++) //reversing individual words on their own
    {
        if(S[End]== ' ')
        {
            reverse(S.begin()+start, S.begin()+End);
            start=End+1;
        }
    }
    reverse(S.begin()+start, S.begin()+ S.length()-1); //reversing last word separately
    reverse(S.begin(), S.end());
}

int main(){

string s;
cout<<"Enter the string: ";
getline(cin, s);

wordReverse(s);
cout<<s;


}

