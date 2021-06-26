#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void Display(string Str)
{
    cout<<endl<<Str<<endl<<endl;
}

void Toggle(string str)
{
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]>=65 && str[i]<=90)
            str[i]+=32;
        else if(str[i]>=97 && str[i]<=122)
            str[i]-=32;
    }
    cout<<"String after toggling cases is(user-defined): ";
    Display(str);
}

int main()
{
    string str, str2;
    cout<<"Enter string 1: ";
    getline(cin, str);

    //Toggle case
    Toggle(str);

    //using inbuilt Transform fn to uppercase
    transform(str.begin(), str.end(), str.begin(), :: toupper);
    cout<<"Uppercase: ";
    Display(str);

    //using inbuilt Transform fn to lowercase
    transform(str.begin(), str.end(), str.begin(), :: tolower);
    cout<<"Lowercase: ";
    Display(str);

    //find greatest number out of a numeric string using inbuilt sort
    string num;
    cout<<"Enter numeric string: ";
    getline(cin, num);
    cout<<"Greatest number formed is: ";
    sort(num.begin(), num.end(), greater<int>() );
    Display(num);

    //finding repeating elements
    string s;
    cout<<"Enter alphabetic string: ";
    getline(cin, s);
    int H[26]={0};

    for(int i=0; i<s.length(); i++)
        H[s[i]-'a']++;

    for(int i=0; i<26; i++)
        if(H[i]>1)
            cout<<char('a'+i)<<" is duplicated "<<H[i]<<" times.\n";

    int Max=H[0];
    char ans;

    for(int i=0; i<26; i++)
        if(H[i]>Max)
            H[i] = Max;
    cout<<"Maximum frequency present is "<<Max<<" given by: ";
    for(int i=0; i<26; i++)
        if(H[i]==Max)
            cout<<char('a'+i)<<" ";

    //







}
