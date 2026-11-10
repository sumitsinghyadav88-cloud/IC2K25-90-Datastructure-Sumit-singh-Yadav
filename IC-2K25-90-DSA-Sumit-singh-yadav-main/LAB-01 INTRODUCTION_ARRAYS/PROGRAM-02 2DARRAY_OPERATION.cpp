
#include <iostream>
using namespace std;

int main()
{
    int a[10][10], r, c, choice, row, col, value;
    bool found;

    cout << "Enter number of rows: ";
    cin >> r;

    cout << "Enter number of columns: ";
    cin >> c;

    if (r < 1 || r > 10 || c < 1 || c > 10)
    {
        cout << "Invalid array size!";
        return 0;
    }

    cout << "\nEnter array elements:\n";

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }

    do
    {
        cout << "\n\n===== 2D ARRAY OPERATIONS =====";
        cout << "\n1. Insert Element";
        cout << "\n2. Delete Element";
        cout << "\n3. Search Element";
        cout << "\n4. Display Array";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter row, column and value: ";
                cin >> row >> col >> value;

                if (row >= 1 && row <= r &&
                    col >= 1 && col <= c)
                {
                    a[row - 1][col - 1] = value;
                    cout << "Element inserted successfully!";
                }
                else
                {
                    cout << "Invalid position!";
                }
                break;

            case 2:
                cout << "Enter row and column to delete: ";
                cin >> row >> col;

                if (row >= 1 && row <= r &&
                    col >= 1 && col <= c)
                {
                    a[row - 1][col - 1] = 0;
                    cout << "Element deleted successfully!";
                }
                else
                {
                    cout << "Invalid position!";
                }
                break;

            case 3:
                cout << "Enter element to search: ";
                cin >> value;

                found = false;

                for (int i = 0; i < r; i++)
                {
                    for (int j = 0; j < c; j++)
                    {
                        if (a[i][j] == value)
                        {
                            cout << "\nElement found at Row "
                                 << i + 1 << " and Column "
                                 << j + 1;

                            found = true;
                        }
                    }
                }

                if (!found)
                {
                    cout << "Element not found!";
                }
                break;

            case 4:
                cout << "\n2D Array Elements:\n";

                for (int i = 0; i < r; i++)
                {
                    for (int j = 0; j < c; j++)
                    {
                        cout << a[i][j] << "\t";
                    }

                    cout << endl;
                }
                break;

            case 5:
                cout << "Program terminated.";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 5);

    return 0;
}
