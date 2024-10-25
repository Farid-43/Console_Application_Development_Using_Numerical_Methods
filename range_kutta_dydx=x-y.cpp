#include <bits/stdc++.h>
using namespace std;


double f(double x, double y)
{
    return x - y;
}

// Defined exact solution: y_exact(x) = x - 1 + 2e^(-x)
double y_exact(double x)
{
    return x - 1 + 2 * exp(-x);
}

int main()
{

    double x0 = 0.0;
    double y0 = 1.0;
    double h = 0.1;
    double xn = 10.0;
    int n = (int)((xn - x0) / h);

    cout << setw(10) << "Iter" << setw(10) << "X"
         << setw(15) << "Y (RK4)" << setw(15) << "Y (Exact)"
         << setw(15) << "Abs Error" << endl;

    double x = x0;
    double y = y0;
    double mean_absolute_error = 0.0;
    cout << setw(10) << 0 << setw(10) << x << setw(15) << fixed << setprecision(6) << y
         << setw(15) << fixed << setprecision(6) << y_exact(x) << setw(15) << fixed << setprecision(10) << fabs(y - y_exact(x)) << endl;


    for (int i = 1; i <= n; ++i)
    {

        double k1 = h * f(x, y);
        double k2 = h * f(x + 0.5 * h, y + 0.5 * k1);
        double k3 = h * f(x + 0.5 * h, y + 0.5 * k2);
        double k4 = h * f(x + h, y + k3);


        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        x = x + h;

        double y_exact_val = y_exact(x);
        double abs_error = fabs(y - y_exact_val);
        mean_absolute_error += abs_error;


        cout << setw(10) << i
             << setw(10) << fixed << setprecision(6) << x
             << setw(15) << fixed << setprecision(6) << y
             << setw(15) << fixed << setprecision(6) << y_exact_val
             << setw(15) << fixed << setprecision(10) << abs_error << endl;

    }
    mean_absolute_error /= n;
    cout << "\nMean Absolute Error: " << mean_absolute_error << endl;

    return 0;
}







