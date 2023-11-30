//Operator overloading without class
#include<iostream>
#include<string.h>
using namespace std;
int operator-(string a,string b)
{
    if(a==b)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    string s1,s2;
    cout<<"Enter the first word: "<<endl;
    cin>>s1;
    cout<<"Enter the second word: "<<endl;
    cin>>s2;
    int diff=s1-s2;
    if(diff==0)
    {
        cout<<"Same"<<endl;
    }
    else
    {
        cout<<"Not same."<<endl;
    }
    return 0;
}