#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string song;
    Node *next;
    Node *prev;

    Node(string s)
    {
        song = s;
        next = NULL;
        prev = NULL;
    }
};

class List
{
    Node *head;

public:
    List()
    {
        head = NULL;
    }

    void pushFront(string s)
    {
        Node *newNode = new Node(s);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        display();
    }

    void pushBack(string s)
    {
        Node *newNode = new Node(s);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }

        display();
    }

    void insertAfter(string find, string s)
    {
        Node *temp = head;

        while (temp != NULL && temp->song != find)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Song not found\n";
            display();
            return;
        }

        Node *newNode = new Node(s);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;

        display();
    }

    void popFront()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty\n";
            return;
        }

        Node *temp = head;

        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }

        delete temp;

        display();
    }

    int count()
    {
        int c = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            c++;
            temp = temp->next;
        }

        return c;
    }

    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->song << " ";
            temp = temp->next;
        }

        cout << "\nCount: " << count() << "\n";
    }
};

int main()
{
    List playlist;

    playlist.pushFront("S1");
    playlist.pushBack("S2");
    playlist.pushBack("S3");
    playlist.insertAfter("S1", "S4");
    playlist.popFront();
    playlist.insertAfter("S3", "S5");

    return 0;
}