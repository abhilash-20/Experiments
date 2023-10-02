#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
class account
{
protected:
    string name, type;
    int accno;

public:
    void setaccount(string n, int acc, string t)
    {
        name = n;  
        accno = acc;
        type = t;
    }
};

class savings : public account
{
public:
    float bal;
    void setsavings(string n, int acc, string type, float b)
    {
        setaccount(n, acc, type);
        bal = b;
        cout << "Your Savings Account has been created successfully" << endl;
    }
    void deposit(float amt)
    {
        bal += amt;
        cout << "Balance after your recent deposit/deposits: " << bal << endl;
    }
    void withdraw(float remove)
    {
        if (remove > bal)
        {
            cout << "Insufficient Balance." << endl;
        }
        else
        {
            bal -= remove;
            cout << "Balance Available: " << bal << endl;
        }
    }
    void calc_interest()
    {
        float ci, t;
        cout << "Calculating interest" << endl;
        cout << "Rate of interest is 6.9% and interst is compounded quaterly." << endl;
        cout << "Enter the time period of investment(in years, and consider the months in decimal.)" << endl;
        cin >> t;
        ci = bal * pow((1 + 0.068 / 4), (4 * t)) - bal;
        cout << "The interest added is Rs: " << ci << endl;
        bal += ci;
        display();
    }
    void display()
    {
        cout << "Current Balance: " << bal << endl;
    }
};

class current : public account
{
public:
    float bal;
    float min_balance = 1000.0;
    void setcurrent(string n, int acc, string type, float b)
    {
        setaccount(n, acc, type);
        if (b > min_balance)
        {
            bal = b;
            cout << "Your Current Account has been successfully created." << endl;
        }
        else
        {
            cout << "Your balance is lower than the minimum balance ie." << min_balance << endl;
        }
    }
    void deposit_chk(float amount)
    {
        bal += amount;
        cout << "Your balance after deposit through check is: " << bal;
    }
    void withdraw_chk(float amount)
    {
        if (amount > bal)
        {
            cout << "Insufficient balance" << endl;
        }
        else
        {
            bal -= amount;
        }
        penal();
    }
    void penal()
    {
        float p = 250.0;
        if (bal < min_balance)
        {
            cout << "Penalty of Rs. " << p << " is administered." << endl;
            bal -= p;
        }
        display();
    }
    void display()
    {
        cout << "Current balance: " << bal << endl;
    }
};

int main()
{
    int c1 = -1, c2 = -1;
    savings a[10];
    current b[10];
    string name, type;
    int acc, ch1, ch2;
    float amount, bal;
    while (1)
    {
        cout << "Welcome!" << endl;
        cout << "Enter the number assigned to the options. You can choose from the following options: " << endl;
        cout << "1.Create an account." << endl
             << "2.Banking Options" << endl
             << "3.Exit" << endl;
        cin >> ch1;
        if (ch1 == 1)
        {
            cout << "Enter the type of account you want to create: " << endl;
            cout << "a) Savings" << endl
                 << "b) Current" << endl;
            cin >> type;
            if (type == "Savings")
            {
                c1++;
                cout << "Enter your name: " << endl;
                cin >> name;
                cout << "Enter your initial balance: " << endl;
                cin >> bal;
                a[c1].setsavings(name, c1 + 1, type, bal);
            }
            else
            {
                if (type == "Current")
                {
                    c2++;
                    cout << "Enter your name: " << endl;
                    cin >> name;
                    cout << "Enter your initial balance: " << endl;
                    cin >> bal;
                    b[c2].setcurrent(name, c2 + 1, type, bal);
                }
            }
        }
        else if (ch1 == 2)
        {
            cout << "Enter the type of account you have in our bank" << endl;
            cin >> type;
            if (type == "Savings")
            {
                while (1)
                {
                    cout << "You can perform the following operations." << endl;
                    cout << "1. Deposit" << endl
                         << "2. Withdraw" << endl
                         << "3.Calculate Interest" << endl
                         << "4. Display" << endl;
                    cin >> ch2;
                    if (ch2 == 1)
                    {
                        cout << "enter the amount" << endl;
                        cin >> amount;
                        cout << "Enter the Account number" << endl;
                        cin >> acc;
                        a[acc - 1].deposit(amount);
                    }
                    if (ch2 == 2)
                    {
                        cout << "Enter the amount" << endl;
                        cin >> amount;
                        cout << "Enter your account number" << endl;
                        cin >> acc;
                        a[acc - 1].withdraw(amount);
                    }
                    if (ch2 == 3)
                    {
                        cout << "Enter your account number: " << endl;
                        cin >> acc;
                        a[acc - 1].calc_interest();
                    }
                    if (ch2 == 4)
                    {
                        cout << "Enter your account number" << endl;
                        cin >> acc;
                        a[acc - 1].display();
                    }
                    if (ch2 == 5)
                    {
                        exit(1);
                    }
                }
            }
            else if (type == "Current")
            {
                while (1)
                {
                    cout << "Enter the number assigned to the options. You can choose from the following options: " << endl;
                    cout << "1.Deposit through Cheque." << endl
                         << "2. Withdraw through Cheque" << endl
                         << "3. Calculating Penalty" << endl
                         << "4. Display" << endl
                         << "5. Exit" << endl;
                    cin >> ch2;
                    if (ch2 == 1)
                    {
                        cout << "Enter the amount you want to deposit via cheque" << endl;
                        cin >> amount;
                        cout << "Enter your account number" << endl;
                        cin >> acc;
                        b[acc - 1].deposit_chk(amount);
                    }
                    if (ch2 == 2)
                    {
                        cout << "Enter the amount you want to withdraw via cheque" << endl;
                        cin >> amount;
                        cout << "Enter your account number" << endl;
                        cin >> acc;
                        b[acc - 1].withdraw_chk(amount);
                    }
                    if (ch2 == 3)
                    {
                        cout << "Enter your account number" << endl;
                        cin >> acc;
                        b[acc - 1].penal();
                    }
                    if (ch2 == 4)
                    {
                        cout << "Enter your account number" << endl;
                        cin >> acc;
                        b[acc - 1].display();
                    }
                    if (ch2 == 5)
                    {
                        exit(0);
                    }
                }
            }
        }
        else if (ch1 == 3)
        {
            exit(0);
        }
    }
    return 0;
}
