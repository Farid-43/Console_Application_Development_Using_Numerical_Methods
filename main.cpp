#include "bits/stdc++.h"
#include "Non_Linear.cpp"
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
        arr.clear();
        cout << "Select method to solve non linear equation :" << endl;
        cout << "1: Bisection method" << endl;
        cout << "2: False position method" << endl;
        cout << "3: Newton raphson method" << endl;
        cout << "4: Secant method" << endl;
        cout << "5:Exit" << endl;
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
    return 0;
}