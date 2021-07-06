#include<bits/stdc++.h>
#include<string>
using namespace std;

//compute no. of strings falling before reqd string +1 using factorial, takes O(n)
const int CHAR = 256;

int fact(int n)
{
    int mul = 1;
    for(int i=n; i>1; i--)
        mul*=i;
    return mul;
}

void lexiRank(string &s)
{
    int count[CHAR] = {0};
    int n = s.length();
    int ans = 1;
    int prod = fact(n);

    //filling count array with string
    for(int i=0; i<n; i++)
    {
        count[s[i]]++;
    }

    //taking cumulative sum of counts to get internal ranking of letters
    for(int i=1; i<CHAR; i++)
    {
        count[i]+= count[i-1];
    }

    //adding ranks of all previous combos
    for(int i=0; i<n-1; i++)
    {
        prod = prod/(n-i);
        ans = ans + count[s[i]-1]*prod;
        for(int j=s[i]; j<CHAR; j++)
            count[j]--;
    }
    cout<<ans;
}
int main()
{
    string s;
    cout<<"Enter string to find lexicographic rank of it: ";
    cin>>s;

    lexiRank(s);
}
