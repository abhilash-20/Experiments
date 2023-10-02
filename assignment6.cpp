#include <iostream>
using namespace std;
class shape
{
public:
    double s1, s2;
    void get_data();
     virtual double display_area()=0;
};

void shape::get_data()
{
    cout << "Enter length of side 1: " << endl;
    cin >> s1;
    cout << "Enter length of side 2: " << endl;
    cin >> s2;
}
class triangle : public shape
{
public:
    double display_area()
    {
        return (s1 * s2) / 2;
    }
};
class rectangle : public shape
{
public:
    double display_area()
    {
        return s1 * s2;
    }
};

int main()
{
    triangle a;
    rectangle b;
    cout << "For Triangle: " << endl;
    a.get_data();
    cout << "The area of a triangle is: " << a.display_area()<<endl;
    cout << "For Rectangle: " << endl;
    b.get_data();
    cout << "The area of rectangle is: " << b.display_area()<<endl;
    return 0;
}