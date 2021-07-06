#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

const int CHAR = 256;

bool isSame(int t[], int p[])
{
    for(int i=0; i<CHAR; i++)
        if(t[i]!=p[i])
            return false;
    return true;
}

bool anagramSearch(string &txt, string &pat)
{
    int p[CHAR] = {0};
    int t[CHAR] = {0};

    //first computing hash array for pat and first hash array for txt window
    for(int i=0; i<pat.length(); i++)
    {
        p[pat[i]]++;
        t[txt[i]]++;
    }

    //sliding pat over txt
    for(int i=pat.length(); i<=txt.length(); i++)
    {
        if(isSame(t, p))
            return true;
        t[txt[i]]++; //adding last char of new window
        t[txt[i-pat.length()]]--; //decrementing first char of prev window
    }
    return false;
}

int main()
{
    string txt, pat;
    cout<<"Enter main string to perform searching in: ";
    getline(cin, txt);
    cout<<"Enter the pattern to search: ";
    getline(cin, pat);
    if(anagramSearch(txt, pat))
        cout<<"Pattern or its anagram is present in main string.";
    else
        cout<<"Pattern not present.";
}

