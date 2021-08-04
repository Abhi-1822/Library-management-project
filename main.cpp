#include <iostream>
#include <stdlib.h>
#include "Student.h"
int loginuser();
using namespace std;

int main()
{
    system("CLS");
    Student s;
    stu *student;
    int f;
    cout << "\t\t\t\t\t\t\tLibrary Management" << endl;
    cout << "\t\t\t\t\t\t\t    Login Page" << endl;
    while (true)
    {
        cout << "1)Login as Admin" << endl;
        cout << "2)Login as Student" << endl;
        cout << "3)Exit" << endl;
        cout << "Enter your choice:  ";
        int c;
        cin >> c;
        if (c == 1)
        {
            int adm;
            cout << "\t\t\t\t\t\t\tAdministrator Login" << endl;
            while (true)
            {
                adm = loginuser();
                if (adm == 0)
                {
                    cout << "Enter correct Username and Password" << endl;
                }
                else
                {
                    cout << "\nLogged in successfully\n";
                    f = 1;
                    break;
                }
            }
            break;
        }
        else if (c == 2)
        {
            cout << "\t\t\t\t\t\t\tStudent Login" << endl;
            while (true)
            {
                student = s.loginstu();
                if (student == NULL)
                {
                    cout << "Enter correct roll number" << endl;
                }
                else
                {
                    f = 2;
                    break;
                }
            }
            break;
        }
        else if (c == 3)
        {
            return 0;
        }
        else
        {
            cout << "\nEnter correct choice";
        }
    }

    if (f == 1)
    {
        while (true)
        {
            system("CLS");
            cout << endl
                 << endl
                 << "\t\t\t\t\t\t\t\tAdministrator" << endl
                 << endl;
            cout << "\t\t\t\t\t\t************************************************" << endl;
            cout << "\t\t\t\t\t\t* Press 1 to see all books                     *" << endl;
            cout << "\t\t\t\t\t\t* Press 2 to see details of particular book    *" << endl;
            cout << "\t\t\t\t\t\t* Press 3 to add a book                        *" << endl;
            cout << "\t\t\t\t\t\t* Press 4 to delete a book                     *" << endl;
            cout << "\t\t\t\t\t\t* Press 5 to exit                              *" << endl;
            cout << "\t\t\t\t\t\t************************************************" << endl;
            int q;
            cin >> q;
            if (q == 1)
            {
                s.get_booklist();
                cin.get();
                cin.get();
            }
            else if (q == 2)
            {
                s.particular_book();
                cin.get();
                cin.get();
            }
            else if (q == 3)
            {
                s.add_book();
                cin.get();
                cin.get();
            }
            else if (q == 4)
            {
                s.delete_book();
                cin.get();
                cin.get();
            }

            else if (q == 5)
                return 0;
            else
            {
                cout << "Enter correct choice" << endl;
            }
        }
    }

    else if (f == 2)
    {
        while (true)
        {
            system("CLS");
            cout << endl
                 << endl
                 << "Student Name:" << student->name << "\t\t\t\t\t\t\t\t\t\tRoll Number : " << student->roll_no << endl
                 << endl;
            cout << "\t\t\t\t\t\t************************************************" << endl;
            cout << "\t\t\t\t\t\t* Press 1 to see issued books to this student  *" << endl;
            cout << "\t\t\t\t\t\t* Press 2 to issue a book                      *" << endl;
            cout << "\t\t\t\t\t\t* Press 3 to return a book                     *" << endl;
            cout << "\t\t\t\t\t\t* Press 4 to login another student             *" << endl;
            cout << "\t\t\t\t\t\t* Press 5 to exit                              *" << endl;
            cout << "\t\t\t\t\t\t************************************************" << endl;
            int q;
            cin >> q;
            if (q == 1)
            {
                s.display(student);
                cin.get();
                cin.get();
            }
            else if (q == 2)
            {
                s.get_book(student);
                cin.get();
                cin.get();
            }
            else if (q == 3)
            {
                s.display(student);
                s.return_book(student);

                cin.get();
                cin.get();
            }
            else if (q == 4)
            {
                while (true)
                {
                    student = s.loginstu();
                    if (student == NULL)
                    {
                        cout << "Enter correct roll number" << endl;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else if (q == 5)
                return 0;
            else
            {
                cout << "Enter correct choice" << endl;
            }
        }
    }

    return 0;
}
int loginuser()
{
    string x = "username", y = "password";
    string usern, pass;
    cout << "\t\t\t\t\t\t\t  Enter Username" << endl;
    cout << "\t\t\t\t\t\t\t     ";
    cin >> usern;
    cout << "\t\t\t\t\t\t\t  Enter password" << endl;
    cout << "\t\t\t\t\t\t\t     ";
    cin >> pass;
    if (usern == x && pass == y)
        return 1;
    return 0;
}
