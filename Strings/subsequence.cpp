#include<iostream>
#include<string>
using namespace std;

//subsequence of ABCDE is AE, same order but not continuous O(m+n)

bool substring(string S, string sub)
{
    if(sub.length()>S.length())
        return false;

    int i, j = 0;
    while(i<S.length() && j<sub.length())
    {
        if(S[i]==sub[j])
            j++;
        i++;
    }
    if(j==sub.length())
        return true;
    return false;
    //return(j==sub.length) optimize
}

int main(){

string s, sub;
cout<<"Enter the string: ";
getline(cin, s);
cout<<"Enter subsequence to search: ";
getline(cin, sub);

if(substring(s, sub))
    cout<<sub<<" is a subsequence!";
else
    cout<<sub<<" is not a subsequence!";

}


