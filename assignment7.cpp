//Implementation of stack using template in Cpp
#include <iostream>
using namespace std;
template <class T>
class stacks
{
public:
    T *a;
    int top = -1;
    stacks()
    {
        a = new T[50];
    }
    void push()
    {
        T info;
        if (top == 49)
        {
            cout << "Stack is full" << endl;
            return;
        }
        //top++;
        cout << "Enter an element: ";
        cin >> info;
        cout << endl;
        a[++top] = info;
    }
    T pop()
    {
        T info;
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return 0;
        }
        info = a[top];
        top--;
        return info;
    }
};

int main()
{
    stacks<int> a;
    int add, del;
    cout << "Enter the number of elements you want to enter: " << endl;
    ;
    cin >> add;
    for (int i = 0; i < add; i++)
    {
        a.push();
    }
    cout << "Enter the number of elements you want to remove: " << endl;
    cin >> del;
    for (int i = 0; i < del; i++)
    {
        int rem = a.pop();
        cout << rem << " has been removed." << endl;
    }
    return 0;
}