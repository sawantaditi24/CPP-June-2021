
#include<iostream>
#include<string>
using namespace std;

//leftmost repeating char of ABBCADE is A, O(n)

const int CHAR = 256; //taking all characters

int leftmostRep(string S)
{
    int H[CHAR]={0};

    for(int i=0; i<S.length(); i++)
        H[S[i]]++;

    for(int i=0; i<S.length(); i++)
        if(H[S[i]]>1)
            return i;

    return -1;
}

int main(){

string s, sub;
cout<<"Enter the string: ";
getline(cin, s);

if(leftmostRep(s)!=-1)
    cout<<"Index of leftmost repeating character is: "<<leftmostRep(s);
else
    cout<<" No repetitions. ";

}



