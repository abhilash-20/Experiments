//Operator Overloading
#include <iostream>
using namespace std;
class FLOAT
{
private:
    float value;

public:
    FLOAT(float v)
    {
        value = v;
    }
    FLOAT operator+(FLOAT &second)
    {
        return FLOAT(value + second.value);
    }

    FLOAT operator-(FLOAT &second)
    {
        return FLOAT(value - second.value);
    }

    FLOAT operator*(FLOAT &second)
    {
        return FLOAT(value * second.value);
    }

    FLOAT operator/(FLOAT &second)
    {
        return FLOAT(value / second.value);
    }

    void display()
    {
        cout << value << endl;
    }
};
int main()
{
    FLOAT num1(5.5);
    FLOAT num2(3.3);
    cout << "First Number: ";
    num1.display();
    cout << "Second Number: ";
    num2.display();
    FLOAT sum = num1 + num2;
    cout << "Result of num1+num2: ";
    sum.display();
    FLOAT diff = num1 - num2;
    cout << "Result of num1-num2: ";
    diff.display();
    FLOAT prd = num1 * num2;
    cout << "Result of num1*num2: ";
    prd.display();
    FLOAT div = num1 / num2;
    cout << "Result of num1/num2: ";
    div.display();
    return 0;
}