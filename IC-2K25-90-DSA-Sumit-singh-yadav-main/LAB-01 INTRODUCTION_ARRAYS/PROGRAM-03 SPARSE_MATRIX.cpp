
#include <iostream>
using namespace std;

int main()
{
    int a[10][10], sparse[100][3];
    int r, c, k = 1;

    cout << "Enter number of rows: ";
    cin >> r;

    cout << "Enter number of columns: ";
    cin >> c;

    if (r < 1 || r > 10 || c < 1 || c > 10)
    {
        cout << "Invalid matrix size!";
        return 0;
    }

    cout << "\nEnter matrix elements:\n";

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }

    sparse[0][0] = r;
    sparse[0][1] = c;

    int count = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = a[i][j];

                k++;
                count++;
            }
        }
    }

    sparse[0][2] = count;

    cout << "\nOriginal Matrix:\n";

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nSparse Matrix (Triplet Representation):\n";
    cout << "Row\tColumn\tValue\n";

    for (int i = 0; i <= count; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << sparse[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
