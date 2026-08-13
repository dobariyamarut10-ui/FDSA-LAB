#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of items" << endl;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << endl;
        cin >> arr[i];
    }

    cout << "Your original array is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    int h;
    cout << endl << "Enter number of hours" << endl;
    cin >> h;

    h = h % n;

    for (int count = 0; count < h; count++)
    {
        int temp = arr[0];

        for (int i = 0; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        arr[n - 1] = temp;
    }

    cout << "Final display order is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}