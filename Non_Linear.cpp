#include "bits/stdc++.h"
using namespace std;

double fxx(double x, vector<double> arr)
{
    double ans = 0;
    int n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        ans += pow(x, i) * arr[i];
    }
    return ans;
}

double ddx(double x, vector<double> arr)
{
    int n = arr.size();
    double ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += pow(x, i - 1) * arr[i] * i;
    }
    return ans;
}

double secantMethod(double x1, double x2, double tolerance, int maxIterations, vector<double> arr)
{
    double fx1, fx2, x3, fx3;

    for (int iter = 0; iter < maxIterations; iter++)
    {
        fx1 = fxx(x1, arr);
        fx2 = fxx(x2, arr);

        x3 = x2 - (fx2 * (x2 - x1) / (fx2 - fx1));
        fx3 = fxx(x3, arr);

        if (fabs(fx3) < tolerance || fabs(x3 - x2) < tolerance)
        {
            return x3;
        }

        x1 = x2;
        x2 = x3;
    }
    return x2;
}

double newtonRaphson(double x, double tolerance, int maxIterations, vector<double> arr)
{
    double fx, dx;
    for (int iter = 0; iter < maxIterations; ++iter)
    {
        fx = fxx(x, arr);
        dx = ddx(x, arr);
        if (fabs(dx) < tolerance)
            break;
        double x1 = x - (fx / dx);
        if (fabs(x1 - x) < tolerance)
            return x1;
        x = x1;
    }
    return x;
}
double sq(double x, vector<double> arr)
{
    double ans = arr[0] * x * x + arr[1] * x + arr[2];
    return ans;
}
double cube(double x, vector<double> arr)
{
    double ans = arr[0] * x * x * x + arr[1] * x * x + arr[2] * x + arr[3];
    return ans;
}
double quadratic(double x, vector<double> arr)
{
    double ans = arr[0] * x * x * x * x + arr[1] * x * x * x + arr[2] * x * x + arr[3] * x + arr[4];
    return ans;
}
void bisection(double mini, double maxa, int n, vector<double> arr)
{
    double a, b, i;
    double aa, bb, mid, mm;
    set<double> ans;
    for (i = mini - 1; i <= maxa + 1; i++)
    {
        a = i, b = i + 1;
        if (n == 3)
        {
            aa = sq(a, arr);
            bb = sq(b, arr);
        }
        else if (n == 4)
        {
            aa = cube(a, arr);
            bb = cube(b, arr);
        }
        else
        {
            aa = quadratic(a, arr);
            bb = quadratic(b, arr);
        }
        if (aa == 0)
        {
            ans.insert(a);
            if (bb == 0)
            {
                ans.insert(b);
            }
            continue;
        }
        if (bb == 0)
        {
            ans.insert(b);
            if (aa == 0)
            {
                ans.insert(a);
            }
            continue;
        }
        if (aa * bb < 0)
        {
            //
            mid = (a + b) / 2;
            // cout << mid << endl;
            double prev = mid;
            if (n == 3)
                mm = sq(mid, arr);
            else if (n == 4)
                mm = cube(mid, arr);
            else
                mm = quadratic(mid, arr);

            while (fabs(mm) > 1e-6)
            {
                mid = (a + b) / 2;
                if (n == 3)
                    mm = sq(mid, arr);
                else if (n == 4)
                    mm = cube(mid, arr);
                else
                    mm = quadratic(mid, arr);
                if ((mm < 0 && aa < 0) || (mm > 0 && aa > 0))
                {
                    a = mid;
                    aa = mm;
                }
                else
                {
                    b = mid;
                    bb = mm;
                }
                // cout << mid << endl;
                prev = mid;
            }
            ans.insert(mid);
        }
    }
    cout << "Root : ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}

void False_Position(double mini, double maxa, int n, vector<double> arr)
{
    double a, b, i;
    double aa, bb, mid, mm;
    set<double> ans;
    for (i = mini - 1; i <= maxa + 1; i++)
    {
        a = i, b = i + 1;
        if (n == 3)
        {
            aa = sq(a, arr);
            bb = sq(b, arr);
        }
        else if (n == 4)
        {
            aa = cube(a, arr);
            bb = cube(b, arr);
        }
        else
        {
            aa = quadratic(a, arr);
            bb = quadratic(b, arr);
        }
        if (aa == 0)
        {
            ans.insert(a);
            if (bb == 0)
            {
                ans.insert(b);
            }
            continue;
        }
        if (bb == 0)
        {
            ans.insert(b);
            if (aa == 0)
            {
                ans.insert(a);
            }
            continue;
        }
        if (aa * bb < 0)
        {
            // mid = (a + b) / 2;
            mid = (a * (bb)-b * aa) / (bb - aa);
            double prev = mid;
            if (n == 3)
                mm = sq(mid, arr);
            else if (n == 4)
                mm = cube(mid, arr);
            else
                mm = quadratic(mid, arr);

            while (fabs(mm) > 1e-6)
            {
                mid = (a * (bb)-b * aa) / (bb - aa);
                // cout << b << endl;
                if (n == 3)
                    mm = sq(mid, arr);
                else if (n == 4)
                    mm = cube(mid, arr);
                else
                    mm = quadratic(mid, arr);
                if ((mm < 0 && aa < 0) || (mm > 0 && aa > 0))
                {
                    a = mid;
                    aa = mm;
                }
                else
                {
                    b = mid;
                    bb = mm;
                }
                // cout << mid << endl;
                //  cout << fabs(prev - mid) << endl;
                prev = mid;
            }
            ans.insert(mid);
        }
    }
    cout << "Root : ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}
