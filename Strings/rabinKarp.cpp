#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

//uses O(m*(n-m+1)) but better than naive search for larger texts, worse in smaller worse cases

const int q = 101; //a prime number f=to make values in code smaller for computation
#define d 256 //a base to calculate weighted hash functions

void naiveDistinct(string &txt, string &pat)
{
    int n = txt.length();
    int m = pat.length();
    int p = 0,t = 0; //hash functions for pattern and text
    int h = 1;

    //computing d power m-1 to use in calc of t i+1 from t i
    for(int i=1; i<=m-1; i++)
    {
        h = (h*d)%q;
    }

    //computing p and t (p only once and first value of t)
    for(int i=0; i<m; i++)
    {
        p = (p*d + pat[i])%q;
        t = (t*d + txt[i])%q;
    }

    //sliding pat over txt
    for(int i=0; i<=n-m; i++)
    {
        if(p==t)
        {
            bool flag = true;
            for(int j=0; j<m; j++)
            {
                if(txt[i+j]!=pat[j])
                    {
                        flag = false;
                        break;
                    }
            }
            if(flag== true)
            cout<<i<<" ";
        }

        //calculating t next from prev t
        if(i<n-m)
        {
            t = ((d*(t - txt[i]*h)) + txt[i+m])%q;
            if(t<q)
                t+=q; //to keep t positive
        }
    }
}

int main()
{
    string txt, pat;
    cout<<"Enter main string to perform searching in: ";
    getline(cin, txt);
    cout<<"Enter the pattern to search: ";
    getline(cin, pat);
    cout<<"Indices having the pattern: ";
    naiveDistinct(txt, pat);
}


