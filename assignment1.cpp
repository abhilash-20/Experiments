#include <iostream>
#include <string.h>
using namespace std;
class bank
{
    string name, type;
    int acc;
    float balance;

public:
    void create(string n, string t, int accno, float bal)
    {
        name = n;
        type = t;
        acc = accno;
        balance = bal;
    }
    void deposit()
    {
        int amt;
        cout << "Enter the amount you want to deposit: " << endl;
        cin >> amt;
        balance += amt;
    }
    void withdraw()
    {
        int rem;
        cout << "Enter the amount you want to withdraw: " << endl;
        cin >> rem;
        if (rem > balance)
        {
            cout << "Insufficient balance" << endl;
        }
        else
        {
            balance -= rem;
        }
    }

    void display()
    {
        cout << "Name of the Account Holder: " << name << endl;
        cout << "Available Balance: " << balance << endl;
    }
};

int main()
{
    bank accounts[10];
    string name, type;
    int accno, c = -1, ch;
    float balance;
    while (1)
    {
        cout << "Enter:" << endl
             << "1 to Create" << endl
             << "2 to Deposit" << endl
             << "3 to Withdraw" << endl
             << "4 to Display" << endl
             << "5 to exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            c++;
            cout << "Enter your name: " << endl;
            cin >> name;
            cout << "Enter the type of account(Savings/Current): " << endl;
            cin >> type;
            cout << "Enter your last available balance: " << endl;
            cin >> balance;
            accounts[c].create(name, type, c + 1, balance);
            cout << "Your account has been successfully created and your account number is: " << (c + 1) << endl;
            break;
        case 2:
            cout << "Enter your account number: " << endl;
            cin >> accno;
            accounts[accno - 1].deposit();
            break;
        case 3:
            cout << "Enter your account number: " << endl;
            cin >> accno;
            accounts[accno - 1].withdraw();
            break;
        case 4:
            cout << "Enter your account number: " << endl;
            cin >> accno;
            accounts[accno - 1].display();
            break;
        case 5:
            exit(0);
        default:
            cout << "Wrong choice" << endl;
            break;
        }
    }
    return 0;
}
