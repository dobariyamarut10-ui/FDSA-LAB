#include<iostream>
using namespace std;

void sortBuckets(int arr[], int n)
{
    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
            countZero++;
        else if(arr[i] == 1)
            countOne++;
        else
            countTwo++;
    }

    int position = 0;

    for(int i = 0; i < countZero; i++)
    {
        arr[position] = 0;
        position++;
    }

    for(int i = 0; i < countOne; i++)
    {
        arr[position] = 1;
        position++;
    }

    for(int i = 0; i < countTwo; i++)
    {
        arr[position] = 2;
        position++;
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}