
#include<iostream>
#include<string>
using namespace std;

//anagram of ABCDE is BDACE, shuffled order, not continuous, same length O(n)

const int CHAR = 256; //taking all characters

bool anagram(string S, string sub)
{
    int H[CHAR]={0};
    if(sub.length()!= S.length()) return false;

    for(int i=0; i<S.length(); i++)
    {
        H[S[i]]++;
        H[sub[i]]--;
    }

    for(int i=0; i<CHAR; i++)
        if(H[i]!=0)
            return false;

    return true;
}

int main(){

string s, sub;
cout<<"Enter the string: ";
getline(cin, s);
cout<<"Enter string to check for anagram: ";
getline(cin, sub);

if(anagram(s, sub))
    cout<<sub<<" is an anagram!";
else
    cout<<sub<<" is not an anagram!";

}


