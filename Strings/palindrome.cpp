#include<iostream>
#include<string>
using namespace std;


int palindrome(string S)
{
    for(int i=0; i<S.length()/2; i++)
        if(S[i]!=S[S.length()-i-1])
           return 0;

    return 1;
}

int main(){

string s;
cout<<"Enter the string: ";
getline(cin, s);

if(palindrome(s))
    cout<<"Palindrome!";
else
    cout<<"Not a palindrome!";

}
