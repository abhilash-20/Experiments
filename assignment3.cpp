#include <iostream>
#include <string.h>
using namespace std;
class books
{
public:
    char *title, *author, *publisher;
    int stock;
    float price;
    books();
    void input();
    void buy();
    int search(char *, char *);
    void display();
};
books::books()
{
    title = new char[50];
    author = new char[50];
    publisher = new char[50];
    price = 0.0;
    stock = 0;
}

void books::input()
{
    cout << "Enter the title of the book: " << endl;
    cin >> title;
    cout << "Enter name of the Author: " << endl;
    cin >> author;
    cout << "Enter name of the publisher: " << endl;
    cin >> publisher;
    cout << "Enter the price of the book: " << endl;
    cin >> price;
    cout << "Enter stock: " << endl;
    cin >> stock;
}

void books::display()
{
    cout << "Author's Name: " << author << endl;
    cout << "Title: " << title << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Price: " << price << endl;
    cout << "Stock: " << stock << endl;
}
int books::search(char *title1, char *author1)
{
    if (strcmp(title, title1) == 0 && strcmp(author, author1) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void books::buy()
{
    int num;
    cout << "Enter the number of copies you require: " << endl;
    cin >> num;
    if (num <= stock)
    {
        cout << "Your demand has been met." << endl;
        cout << "Price of " << num << " copies is: " << (num * price) << endl;
    }
    else
    {
        cout << "Uh oh! Required copies not available." << endl;
    }
}

int main()
{
    int flag = 0, ch, size;
    char a, title1[50], author1[50];
    cout << "Enter the number of books: " << endl;
    cin >> size;
    books b[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter details of book " << (i + 1) << endl;
        b[i].input();
    }
    while (1)
    {
        cout << "Enter: " << endl
             << "1 to DISPLAY the DETAILS OF A BOOK" << endl
             << "2 to SEARCH FOR A BOOK" << endl
             << "3 to BUY A BOOK" << endl
             << "4 to EXIT" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            for (int i = 0; i < size; i++)
            {
                cout << "Details of book " << (i + 1) << endl;
                b[i].display();
                cout << endl;
            }
            break;

        case 2:
            cout << "Enter the details of the book you want to search: " << endl;
            cout << "Enter Author's Name: " << endl;
            cin >> author1;
            cout << "Title: " << endl;
            cin >> title1;
            for (int i = 0; i < size; i++)
            {
                flag = b[i].search(title1, author1);
                if (flag == 1)
                {
                    cout << "Book is available in aisle:" << (i + 1) << endl;
                }
                if (flag == 0)
                {
                    cout << "Book not present in aisle: " << (i + 1) << endl;
                }
            }

            break;
        case 3:
            int i;
            cout << "Enter the details to search whether the book is available or not" << endl;
            cout << "Author:" << endl;
            cin >> author1;
            cout << "title: " << endl;
            cin >> title1;
            for (i = 0; i < size; i++)
            {
                flag = b[i].search(title1, author1);
                if (flag == 1)
                {
                    cout << "Book is available in aisle " << (i + 1) << "." << endl;
                    b[i].buy();
                    break;
                }
                if (flag == 0)
                {
                    cout << "Sorry, the book is not available in aisle " << (i + 1) << "." << endl;
                }
            }
            break;
        case 4:
            exit(0);
        default:
            cout << "Wrong Input!!" << endl;
            break;
        }
    }
    return 0;
}