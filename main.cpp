#include "bits/stdc++.h"
#include "Non_Linear.cpp"
#include "linear.cpp"
#include "Matrix_Inversion.cpp"
#include "Differential_Equation.cpp"
using namespace std;
const int MOD = 1e9 + 7;
const double PI = acos(-1);

typedef unsigned long long uint;
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)

vector<double> arr;
int main()
{
    FAST;
    while (1)
    {
        cout << "Select Option:" << endl;
        cout << "1: Solution of Linear Equations" << endl;
        cout << "2: Solution of Non-linear Equations" << endl;
        cout << "3: Solution of Differential Equations" << endl;
        cout << "4: Matrix Inversion" << endl;
        cout << "5: Exit" << endl;

        int pick;
        cin >> pick;
        if (pick == 1)
        {
            int n;
            vector<vector<double>> A;
            vector<double> b, x;

            while (true)
            {

                cout << "Enter any option to perform an operation: " << endl;
                cout << "1. Jacobi Method " << endl;
                cout << "2. Gauss Seidel Method " << endl;
                cout << "3. Gauss Elimination Method " << endl;
                cout << "4. Gauss Jordan Elimination Method " << endl;
                cout << "5. LU Factorization Method " << endl;
                cout << "6. Back " << endl;

                int op;
                cin >> op;

                if (op == 6)
                    break;

                switch (op)
                {
                case 1:
                    cout << "Enter the number of variables: " << endl;
                    cin >> n;
                    A.resize(n, vector<double>(n));
                    b.resize(n);

                    cout << "Enter the coefficient matrix and right-hand value: " << endl;
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            cin >> A[i][j];
                        }
                        cin >> b[i];
                    }
                    jacobiMethod(A, b);
                    break;

                case 2:
                    cout << "Enter the number of variables: " << endl;
                    cin >> n;
                    A.resize(n, vector<double>(n));
                    b.resize(n);
                    x.assign(n, 0.0);

                    cout << "Enter the coefficient matrix and right-hand value: " << endl;
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            cin >> A[i][j];
                        }
                        cin >> b[i];
                    }
                    gaussSeidelMethod(A, b);
                    break;

                case 3:
                    cout << "Enter the number of variables: " << endl;
                    cin >> n;
                    A.clear();
                    A.resize(n, vector<double>(n + 1));

                    cout << "Enter the augmented matrix: " << endl;
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j <= n; j++)
                        {
                            cin >> A[i][j];
                        }
                    }
                    gaussElinmination(A);
                    break;

                case 4:
                    cout << "Enter the number of variables: " << endl;
                    cin >> n;
                    A.clear();
                    A.resize(n, vector<double>(n + 1));

                    cout << "Enter the augmented matrix: " << endl;
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j <= n; j++)
                        {
                            cin >> A[i][j];
                        }
                    }
                    gaussJorElimination(A);
                    break;

                case 5:
                    cout << "Enter the number of variables: " << endl;
                    cin >> n;
                    A.resize(n, vector<double>(n));
                    b.resize(n);

                    cout << "Enter the coefficient matrix and right-hand value: " << endl;
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            cin >> A[i][j];
                        }
                        cin >> b[i];
                    }
                    luDecomposition(A, b);
                    break;
                default:
                    cout << "Invalid option. Please try again. " << endl;
                    break;
                }
            }
            /*
                    5 variable
            10   -1    2    1    1   12
            -1   10   -1    2    1   15
            2   -1   10   -1    2   16
            1    2   -1   10   -1   14
            1    1    2   -1   10   13


                    3 variable
                4 -1 0 1
                -1 3 -1 2
                0 -1 5 3
            */
        }
        else if (pick == 2)
        {
            while (1)
            {
                arr.clear();
                cout << "Select method to solve non linear equation :" << endl;
                cout << "1: Bisection method" << endl;
                cout << "2: False position method" << endl;
                cout << "3: Newton raphson method" << endl;
                cout << "4: Secant method" << endl;
                cout << "5: Back" << endl;
                int choice;
                cin >> choice;
                if (choice == 5)
                    break;
                if (choice == 1 || choice == 2)
                {
                    int degree;

                    cout << "Enter the degree of the polynomial (square or cubic or quadratic equation): " << endl;
                    cin >> degree;
                    cout << "Enter the coefficients (highest to lowest degree): " << endl;
                    for (int i = 0; i <= degree; i++)
                    {
                        double coefficient;
                        cin >> coefficient;
                        arr.push_back(coefficient);
                    }
                    double m, x;
                    x = (arr[1] / arr[0]);
                    x *= x;
                    double y = 2 * (arr[2] / arr[0]);
                    double maxa = abs(x - y);
                    double mini = -maxa;
                    if (choice == 1)
                        bisection(mini, maxa, degree + 1, arr);
                    else if (choice == 2)
                        False_Position(mini, maxa, degree + 1, arr);
                    cout << endl;

                    /*
                    Non linear:
                    3
                    1 0 -7 6

                    */
                }
                else if (choice == 3 || choice == 4)
                {
                    int degree;

                    cout << "Enter the degree of the polynomial: " << endl;
                    cin >> degree;
                    cout << "Enter the coefficients (highest to lowest degree): " << endl;
                    for (int i = 0; i <= degree; i++)
                    {
                        double coefficient;
                        cin >> coefficient;
                        arr.push_back(coefficient);
                    }
                    reverse(arr.begin(), arr.end());

                    set<double> uniqueRoots;
                    double intervalStart = -500, intervalEnd = 500;
                    double step = 1;

                    for (double initialGuess = intervalStart; initialGuess <= intervalEnd; initialGuess += step)
                    {
                        double root;
                        if (choice == 3)
                        {
                            root = newtonRaphson(initialGuess, 1e-6, 1000, arr);
                        }
                        else if (choice == 4)
                        {
                            root = secantMethod(initialGuess, initialGuess + step, 1e-6, 1000, arr);
                        }
                        else
                        {
                            cout << "Invalid choice!" << endl;
                            return 1;
                        }

                        bool isUnique = true;
                        for (double foundRoot : uniqueRoots)
                        {
                            if (fabs(foundRoot - root) < 1e-3)
                            {
                                isUnique = false;
                                break;
                            }
                        }

                        if (isUnique && fabs(fxx(root, arr)) < 1e-3)
                        {
                            uniqueRoots.insert(root);
                            cout << "Root found: " << root << endl;
                        }
                    }

                    if (uniqueRoots.empty())
                    {
                        cout << "No real roots found." << endl;
                    }
                }
                else
                {
                    cout << "Invalid choice" << endl;
                    break;
                }
            }
        }
        else if (pick == 3)
        {
            cout << "4th order Range Kutta Method  " << endl;
            cout << "Enter initial condition y0: " << endl;
            double y0;
            cin >> y0;
            cout << "Enter Start value  x0: " << endl;
            double x0;
            cin >> x0;
            cout << "Enter End value x_end: " << endl;
            double x_end;
            cin >> x_end;
            cout << "Enter step size: " << endl;
            double h;
            cin >> h;
            rangeKutta(y0, x0, x_end, h);

            // For Kutta:
            //  double y0 = 1.0;      // Initial condition
            //  double x0 = 0.0;      // Start value of x
            //  double x_end = 5.0;   // End value of x
            //  double h = 0.1;       // Step size
        }
        else if (pick == 4)
        {
            cout << "Matrix Inversion  " << endl;
            int sz;
            cout << "Enter the size of the matrix: " << endl;
            cin >> sz;

            vector<vector<double>> matrix(sz, vector<double>(sz));
            cout << "Enter the matrix elements: " << endl;
            for (int i = 0; i < sz; i++)
            {
                for (int j = 0; j < sz; j++)
                {
                    cin >> matrix[i][j];
                }
            }
            matrixInversion(matrix);
            /*
            For Linear:
            5 variable
           10   -1    2    1    1   12
          -1   10   -1    2    1   15
           2   -1   10   -1    2   16
           1    2   -1   10   -1   14
           1    1    2   -1   10   13


            3 variable
                4 -1 0 1
                -1 3 -1 2
                0 -1 5 3

           For Inversion:
           10   -1    2    1    1
          -1   10   -1    2    1
           2   -1   10   -1    2
           1    2   -1   10   -1
           1    1    2   -1   10
            */
        }
        else if (pick == 5)
            break;
        else
        {
            cout << "Invalid choice:" << endl;
            break;
        }
    }
    cout << "Thank you" << endl;
    return 0;
}