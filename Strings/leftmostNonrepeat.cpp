
#include<iostream>
#include<string>
using namespace std;

//leftmost non-repeating char of ABBCADE is C, O(n) but 1 string traversal

const int CHAR = 256; //taking all characters

int leftmostRep(string S)
{
    int H[CHAR]; //array of first instances indices
    fill(H, H+CHAR, -1); //filling array with -1s

    for(int i=0; i<S.length(); i++)
    {
        if(H[S[i]]==-1)
            H[S[i]]=i;
        else
            H[S[i]]=-2; //repetition
    }

    int Min=INT_MAX;
    for(int i=0; i<CHAR; i++)
        if(H[i]>=0)
            Min=min(Min, H[i]);

    if(Min>0)return Min;
    return -1;
}

int main(){

string s, sub;
cout<<"Enter the string: ";
getline(cin, s);

if(leftmostRep(s)!=-1)
    cout<<"Index of leftmost non-repeating character is: "<<leftmostRep(s);
else
    cout<<" All repetitions. ";

}




