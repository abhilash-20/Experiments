#include<iostream>
#include<string.h>
using namespace std;
class model
{
    private:
        string c;
    public:
        model(string t)
        {
            c=t;
        }
        string data_base()
        {
            if(c=="asfd")
            {
                return("found");
            }
            else{
                return ("not found");
            }
        }
};

class view
{
    private:
        string s;
    public:
        view(string v)
        {
            s=v;
        }
        void displaystr()
        {
            cout<<"Displayed by view class "<<s<<endl;
        }
};

class controller
{
    private: 
        model b;
        view s;
        string x;
    public: 
    controller(const string ptr):b(ptr),s(ptr)
    {}
    void test()
    {
        x=b.data_base();
        cout<<x<<endl;
    }
    void display()
    {
        s.displaystr();
    }
};
int main()
{
    controller a("asdf");
    a.test();
    a.display();
    return 0;
}