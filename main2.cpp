#include "linear.cpp"
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<vector<double>> A;    
    vector<double> b, x;         


    while (true) {
        
        cout << "Enter any option to perform an operation: \n";
        cout << "1. Jacobi Method\n";
        cout << "2. Gauss Seidel Method\n";
        cout << "3. Gauss Elimination Method\n";
        cout << "4. Gauss Jordan Elimination Method\n";
        cout << "5. LU Factorization Method\n";

        int op;
        cin >> op;
        
        switch (op) {
            case 1:
                cout << "Enter the number of variables: ";
                cin >> n;
                A.resize(n, vector<double>(n));
                b.resize(n);

                cout << "Enter the coefficient matrix and right-hand value:\n";
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cin >> A[i][j];
                    }
                    cin >> b[i];
                }
                jacobiMethod(A, b);
                break;

            case 2:
                cout << "Enter the number of variables: ";
                cin >> n;
                A.resize(n, vector<double>(n));
                b.resize(n);
                x.assign(n, 0.0); 

                cout << "Enter the coefficient matrix and right-hand value:\n";
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cin >> A[i][j];
                    }
                    cin >> b[i];
                }
                gaussSeidelMethod(A, b);
                break;

            case 3:
                cout << "Enter the number of variables: ";
                cin >> n;
                A.resize(n, vector<double>(n + 1));

                cout << "Enter the augmented matrix:\n";
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j <= n; j++) {
                        cin >> A[i][j];
                    }
                }
                gaussElinmination(A);
                break;

            case 4:
                cout << "Enter the number of variables: ";
                cin >> n;
                A.resize(n, vector<double>(n + 1));

                cout << "Enter the augmented matrix:\n";
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j <= n; j++) {
                        cin >> A[i][j];
                    }
                }
                gaussJorElimination(A);
                break;

            case 5:
                cout << "Enter the number of variables: ";
                cin >> n;
                A.resize(n, vector<double>(n));
                b.resize(n);

                cout << "Enter the coefficient matrix and right-hand value:\n";
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cin >> A[i][j];
                    }
                    cin >> b[i];
                }
                luDecomposition(A, b);
                break;

            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    }
    return 0;
}
