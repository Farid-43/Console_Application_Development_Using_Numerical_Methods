#include <bits/stdc++.h>
using namespace std;


vector<double> luSolve(vector<vector<double>>& L,vector<vector<double>>& U,vector<double>& b) {
    int n = L.size();
    vector<double> y(n);
    vector<double> x(n);

    for (int i = 0; i < n; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
    return x;
}

void luDecomposition(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U, vector<double> &b) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            U[i][j] = A[i][j];
            for (int k = 0; k < i; k++) {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }

        for (int j = i; j < n; j++) {
            if (i == j) {
                L[i][i] = 1; 
            } 
            else {
                L[j][i] = A[j][i];
                for (int k = 0; k < i; k++) {
                    L[j][i] -= L[j][k] * U[k][i];
                }

                if (U[i][i] == 0) {
                    throw runtime_error("Matrix is singular. LU decomposition cannot be performed.");
                }
                L[j][i] /= U[i][i];
            }
        }
    }


    cout << "Matrix L:" << endl;
    for (const auto& row : L) {
        for (double val : row) {
            cout <<setw(10)<< val;
        }
        cout << endl;
    }

    cout << "Matrix U:" << endl;
    for (const auto& row : U) {
        for (double val : row) {
            cout <<setw(10)<< val;
        }
        cout << endl;
    }

     vector<double> x = luSolve(L, U, b);

    cout << "The solution is: ";
    for (double val : x) {
        cout << val << " ";
    }
    cout << endl;

}



int main() {
    int n;
    cout<<"Enter the number of variables: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);
    cout<<"Enter the coefficient matrix and right hand value: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
        cin >> b[i];
    }

    vector<vector<double>> L(n, vector<double>(n, 0));
    vector<vector<double>> U(n, vector<double>(n, 0));

    luDecomposition(A, L, U, b);
   

    return 0;
}

//System of Equation

/*
4 -1 0 1
-1 3 -1 2
0 -1 5 3

15 5 4 2 5
4 3 6 2 8
4 5 6 6 8
1 7 8 5 2 

*/