#include "bits/stdc++.h"
using namespace std;

double evaluate(double x, vector<double> &arr)
{
    double result = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        result = result * x + arr[i];
    }
    return result;
}

bool rootExists(const set<double> &roots, double newRoot, double tolerance = 1e-6)
{
    for (double root : roots)
    {
        if (fabs(root - newRoot) < tolerance)
        {
            return true;
        }
    }
    return false;
}

vector<pair<double, double>> findInitialIntervals(double mini, double maxa, vector<double> &arr, double step = 0.1)
{
    vector<pair<double, double>> intervals;
    for (double x = mini; x <= maxa; x += step)
    {
        double fa = evaluate(x, arr);
        double fb = evaluate(x + step, arr);
        if (fa * fb <= 0)
        {
            intervals.push_back({x, x + step});
        }
    }
    return intervals;
}

void findRoots(double mini, double maxa, bool useFalsePosition, vector<double> &arr)
{
    set<double> roots;
    auto intervals = findInitialIntervals(mini, maxa, arr);
    const double tolerance = 1e-6;

    for (auto [a, b] : intervals)
    {
        double fa = evaluate(a, arr);
        double fb = evaluate(b, arr);

        if (fabs(fa) < tolerance && !rootExists(roots, a))
        {
            roots.insert(a);
            continue;
        }
        if (fabs(fb) < tolerance && !rootExists(roots, b))
        {
            roots.insert(b);
            continue;
        }

        int maxIter = 100;
        while (maxIter-- && fabs(b - a) > tolerance)
        {
            double c = useFalsePosition ? (a * fb - b * fa) / (fb - fa) : (a + b) / 2;

            double fc = evaluate(c, arr);
            if (fabs(fc) < tolerance)
            {
                if (!rootExists(roots, c))
                {
                    roots.insert(c);
                }
                break;
            }

            if (fc * fa < 0)
            {
                b = c;
                fb = fc;
            }
            else
            {
                a = c;
                fa = fc;
            }
        }

        if (maxIter >= 0 && fabs(b - a) < tolerance)
        {
            double finalRoot = (a + b) / 2;
            if (!rootExists(roots, finalRoot))
            {
                roots.insert(finalRoot);
            }
        }
    }

    cout << "Roots using " << (useFalsePosition ? "False Position" : "Bisection") << ": ";
    for (double root : roots)
    {
        cout << fixed << setprecision(6) << root << " ";
    }
    cout << endl;
}

double fxx(double x, vector<double> &arr)
{
    double ans = 0;
    int n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        ans += pow(x, i) * arr[i];
    }
    return ans;
}

double ddx(double x, vector<double> &arr)
{
    int n = arr.size();
    double ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += pow(x, i - 1) * arr[i] * i;
    }
    return ans;
}

double secantMethod(double x1, double x2, vector<double> &arr, double tolerance = 1e-6, int maxIterations = 1000)
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

double newtonRaphson(double x, vector<double> &arr, double tolerance = 1e-6, int maxIterations = 1000)
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