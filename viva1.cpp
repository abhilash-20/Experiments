#include<iostream>
#include<string.h>
using namespace std;
class STRING
{
    private:
    char a[20];
    public:
    STRING(char b[])
    {
        strcpy(a,b);
    }
    int operator-(STRING s)
    {
        if(strcmp(a,s.a)==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};
int main()
{
    STRING s1("Abhi");
    STRING s2("Swas");
    int diff=s1-s2;
    cout<<"output is: "<<diff<<endl;
}