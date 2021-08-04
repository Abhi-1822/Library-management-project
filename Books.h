#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

struct Node
{
    string ref_num;
    string name;
    int stock;
    string author;
    Node *next;
    Node()
    {
        next = NULL;
    }
};
class Book
{
    Node *head;
    Node *curr;

public:
    Book()
    {
        head = NULL;
        fstream fin;
        fin.open("books.csv", ios::in);
        string line, word, temp;
        {
            getline(fin, line);
            stringstream s(line);
            head = new Node();
            getline(s, word, ',');
            head->ref_num = word;
            getline(s, word, ',');
            head->name = word;
            getline(s, word, ',');
            head->stock = stoi(word);
            getline(s, word, ',');
            head->author = word;
        }

        curr = head;
        getline(fin, line);
        while (!fin.eof())
        {
            stringstream s(line);
            Node *temp = new Node();
            getline(s, word, ',');
            temp->ref_num = word;
            getline(s, word, ',');
            temp->name = word;
            getline(s, word, ',');
            temp->stock = stoi(word);
            getline(s, word, ',');
            temp->author = word;
            curr->next = temp;
            curr = temp;
            getline(fin, line);
        }
        fin.close();
    }

    Node *get_information()
    {
        string b, a;
        cout << "Enter Book name" << endl;
        cin >> b;
        cout << "Enter author" << endl;
        cin >> a;
        Node *temp = head;
        while (temp)
        {
            if (temp->name == b)
            {
                cout << "Book Name : " << temp->name << endl;
                cout << "Book Author : " << temp->author << endl;
                cout << "Book Stock : " << temp->stock << endl
                     << endl;
                if (temp->stock == 0)
                {
                    cout << "Sorry , Book not in stock" << endl;
                    return NULL;
                }
                return temp;
            }
            temp = temp->next;
        }
        cout << "Sorry , Book not found" << endl;
        return NULL;
    }
    Node *book_detail(string ref)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->ref_num == ref)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }
    void book_Insert()
    {
        Node *temp = head;
        Node *newbook = new Node();
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        cout << "Enter title of book: ";
        cin >> newbook->name;
        cout << "Enter author name: ";
        cin >> newbook->author;
        cout << "Enter reference number of book: ";
        cin >> newbook->ref_num;
        cout << "Enter stock of new book: ";
        cin >> newbook->stock;
        temp->next = newbook;
    }
    void delete_book()
    {
        string x, y;
        cout << "Enter book name" << endl;
        cin >> x;
        cout << "Enter author" << endl;
        cin >> y;
        Node *temp = head;
        while (temp)
        {
            if (temp->next->name == x)
            {
                cout << "Book Name : " << temp->next->name << endl;
                cout << "Book Author : " << temp->next->author << endl;
                cout << "Book Stock : " << temp->next->stock << endl
                     << endl;
                cout << "Press 1 to delete this book" << endl;
                cout << "Press 0 to return" << endl;
                int q;
                cin >> q;
                if (q == 1)
                {
                    Node *t = temp->next;
                    temp->next = temp->next->next;
                    delete t;
                    cout << "Book deleted successfully" << endl;
                    return;
                }
                else
                {
                    return;
                }
            }
            temp = temp->next;
        }
        cout << "Sorry , Book not found" << endl;
    }
    void book_list()
    {
        Node *temp = head;
        cout << "Sr." << setw(20) << right << "Book Title" << setw(20) << right << "Author name" << setw(8) << "    Stock   " << endl;
        int s = 1;
        while (temp)
        {
            cout << s << setw(20) << right << temp->name << setw(20) << temp->author << setw(8) << temp->stock << endl;
            temp = temp->next;
            s++;
        }
    }
    ~Book()
    {
        fstream fout;
        fout.open("books.csv", ios::out);
        Node *temp = head;
        while (temp)
        {
            fout << temp->ref_num << "," << temp->name << "," << temp->stock << "," << temp->author << endl;
            temp = temp->next;
        }
    }
};
