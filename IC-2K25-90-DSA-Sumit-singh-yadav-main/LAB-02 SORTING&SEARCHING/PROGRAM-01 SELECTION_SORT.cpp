
#include <iostream>
using namespace std;

int main()
{
    int a[100], n, minIndex, temp;

    cout << "Enter array size: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
                minIndex = j;
        }

        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
