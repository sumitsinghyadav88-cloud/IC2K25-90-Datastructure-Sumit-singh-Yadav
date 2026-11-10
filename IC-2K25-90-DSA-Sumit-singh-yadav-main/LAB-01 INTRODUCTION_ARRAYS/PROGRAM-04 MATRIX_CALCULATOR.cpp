
#include <iostream>
using namespace std;

int main()
{
    int a[10][10], b[10][10], result[10][10];
    int r1, c1, r2, c2, choice;
    int determinant;

    do
    {
        cout << "\n===== MATRIX CALCULATOR =====";
        cout << "\n1. Matrix Addition";
        cout << "\n2. Matrix Multiplication";
        cout << "\n3. Matrix Transpose";
        cout << "\n4. Matrix Determinant";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\nEnter rows and columns of matrices: ";
                cin >> r1 >> c1;

                if (r1 < 1 || r1 > 10 || c1 < 1 || c1 > 10)
                {
                    cout << "Invalid matrix size!";
                    break;
                }

                cout << "Enter first matrix:\n";
                for (int i = 0; i < r1; i++)
                    for (int j = 0; j < c1; j++)
                        cin >> a[i][j];

                cout << "Enter second matrix:\n";
                for (int i = 0; i < r1; i++)
                    for (int j = 0; j < c1; j++)
                        cin >> b[i][j];

                cout << "\nAddition Result:\n";
                for (int i = 0; i < r1; i++)
                {
                    for (int j = 0; j < c1; j++)
                    {
                        result[i][j] = a[i][j] + b[i][j];
                        cout << result[i][j] << "\t";
                    }
                    cout << endl;
                }
                break;

            case 2:
                cout << "\nEnter rows and columns of first matrix: ";
                cin >> r1 >> c1;

                cout << "Enter rows and columns of second matrix: ";
                cin >> r2 >> c2;

                if (r1 < 1 || r1 > 10 || c1 < 1 || c1 > 10 ||
                    r2 < 1 || r2 > 10 || c2 < 1 || c2 > 10)
                {
                    cout << "Invalid matrix size!";
                    break;
                }

                if (c1 != r2)
                {
                    cout << "Multiplication not possible!";
                    break;
                }

                cout << "Enter first matrix:\n";
                for (int i = 0; i < r1; i++)
                    for (int j = 0; j < c1; j++)
                        cin >> a[i][j];

                cout << "Enter second matrix:\n";
                for (int i = 0; i < r2; i++)
                    for (int j = 0; j < c2; j++)
                        cin >> b[i][j];

                for (int i = 0; i < r1; i++)
                {
                    for (int j = 0; j < c2; j++)
                    {
                        result[i][j] = 0;

                        for (int k = 0; k < c1; k++)
                            result[i][j] += a[i][k] * b[k][j];
                    }
                }

                cout << "\nMultiplication Result:\n";
                for (int i = 0; i < r1; i++)
                {
                    for (int j = 0; j < c2; j++)
                        cout << result[i][j] << "\t";

                    cout << endl;
                }
                break;

            case 3:
                cout << "\nEnter rows and columns: ";
                cin >> r1 >> c1;

                if (r1 < 1 || r1 > 10 || c1 < 1 || c1 > 10)
                {
                    cout << "Invalid matrix size!";
                    break;
                }

                cout << "Enter matrix elements:\n";
                for (int i = 0; i < r1; i++)
                    for (int j = 0; j < c1; j++)
                        cin >> a[i][j];

                cout << "\nTranspose Matrix:\n";
                for (int i = 0; i < c1; i++)
                {
                    for (int j = 0; j < r1; j++)
                        cout << a[j][i] << "\t";

                    cout << endl;
                }
                break;

            case 4:
                cout << "\nEnter order of square matrix (1-3): ";
                cin >> r1;

                if (r1 < 1 || r1 > 3)
                {
                    cout << "Only 1x1, 2x2 and 3x3 matrices allowed!";
                    break;
                }

                cout << "Enter matrix elements:\n";
                for (int i = 0; i < r1; i++)
                    for (int j = 0; j < r1; j++)
                        cin >> a[i][j];

                if (r1 == 1)
                {
                    determinant = a[0][0];
                }
                else if (r1 == 2)
                {
                    determinant = a[0][0] * a[1][1]
                                - a[0][1] * a[1][0];
                }
                else
                {
                    determinant =
                        a[0][0] * (a[1][1] * a[2][2]
                                 - a[1][2] * a[2][1])
                      - a[0][1] * (a[1][0] * a[2][2]
                                 - a[1][2] * a[2][0])
                      + a[0][2] * (a[1][0] * a[2][1]
                                 - a[1][1] * a[2][0]);
                }

                cout << "Determinant = " << determinant;
                break;

            case 5:
                cout << "\nThank you for using Matrix Calculator!";
                break;

            default:
                cout << "\nInvalid choice! Please try again.";
        }

    } while (choice != 5);

    return 0;
}
