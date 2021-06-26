#include<iostream>
#include<string>
using namespace std;

// substring of ABCDE is BCD, same order and continuous O(n sq.)
bool substring(string S, string sub)
{
    for(int i=0; i<S.length(); i++)
        for(int j=0; j<=S.length()-i; j++)
            if(S.substr(i, j)==sub)
                return true;
    return false;
}

int main(){

string s, sub;
cout<<"Enter the string: ";
getline(cin, s);
cout<<"Enter substring to search: ";
getline(cin, sub);

if(substring(s, sub))
    cout<<sub<<" is a substring!";
else
    cout<<sub<<" is not a substring!";

}

