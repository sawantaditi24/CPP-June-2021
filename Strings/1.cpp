#include<iostream>
using namespace std;

//basic operations on character array

void Display(char S[])
{
    cout<<"String is: ";
    puts(S);
    cout<<endl;
}

int Length(char s[])
{
    int i;
    for(i=0; s[i]!='\0'; i++){}
    return i;
}

void Toggle(char s[])
{
    for(int i=0; s[i]!='\0'; i++)
    {
        if(s[i]>=65 && s[i]<=90)
            s[i]+=32;
        else if(s[i]>=97 && s[i]<=122)
            s[i]-=32;
    }
}

int countW(char s[])
{
    int countw=0;
    for(int i=0; s[i]!='\0'; i++)
        if(s[i]==' ' && s[i-1]!=' ')
            countw++;
    return countw+1;
}

int countV(char s[])
{
    int countv=0;
    for(int i=0; s[i]!='\0'; i++)
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            countv++;
    return countv;
}

int Validate(char str[])
{
    for(int i=0; str[i]!='\0'; i++)
    {
        if(!(str[i]>=65 && str[i]<=90) && !(str[i]>=97 && str[i]<=122) && !(str[i]>=48 && str[i]<=57))
            return 0;
    }
    return 1;
}

void Reverse(char str2[], char str3[])
{
    int j;
    for(int i=Length(str2)-1, j=0; i>=0; i--, j++)
        str3[j]=str2[i];

    cout<<"After reversing, ";
    Display(str3);
    str3[j]='\0';
}

int main()
{
    char s[30];
    cout<<"Enter string: ";
    gets(s);
    Display(s);

    //finding length
    cout<<"Length is: "<<Length(s)<<endl;

    //Toggle case
    Toggle(s);
    cout<<"After toggling, ";
    Display(s);

    //Counting words
    cout<<"Number of words in string: "<<countW(s)<<endl;

    //Counting vowels and consonants
    cout<<"Number of vowels in string: "<<countV(s)<<endl;
    cout<<"Number of consonants in string: "<<Length(s) - countV(s)<<endl;

    //Validating a string
    char str[20];
    cout<<"\nEnter string to validate (valid string contains only alphabets and numbers): ";
    cin>>str;

    if(Validate(str))
        cout<<"Valid string\n";
    else
        cout<<"Invalid string\n";

    //Reversing string
    char str2[] = "yo yo ananyaa singh!";
    int len3 = Length(str2);
    //cout<<Length(str2)<<endl;
    char str3[len3];

    Display(str2);
    Reverse(str2, str3);

}
