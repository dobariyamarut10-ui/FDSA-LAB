#include <iostream>
using namespace std;

class Stack
{
    int stack[100];
    int top;
    int size;

public:
    Stack(int n)
    {
        size = n;
        top = -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Error: Stack is full" << endl;
            return;
        }

        top++;
        stack[top] = value;

        cout << "Tray placed successfully" << endl;
        cout << "Current top tray: " << stack[top] << endl;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Error: Stack is empty" << endl;
            return;
        }

        cout << "Tray taken: " << stack[top] << endl;
        top--;

        if (isEmpty())
        {
            cout << "Current top tray: Empty" << endl;
        }
        else
        {
            cout << "Current top tray: " << stack[top] << endl;
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Current top tray: " << stack[top] << endl;
        }
    }
};

int main()
{
    int size;

    cout << "Enter stack size: ";
    cin >> size;

    Stack tray(size);

    int choice;
    int value;

    do
    {
        cout << endl;
        cout << "1. Place Tray" << endl;
        cout << "2. Take Tray" << endl;
        cout << "3. Display Top Tray" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter tray value: ";
                cin >> value;
                tray.push(value);
                break;

            case 2:
                tray.pop();
                break;

            case 3:
                tray.peek();
                break;

            case 4:
                cout << "Program ended" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 4);

    return 0;
}