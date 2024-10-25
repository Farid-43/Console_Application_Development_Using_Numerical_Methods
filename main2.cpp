#include "linear.cpp"
#include "matrixInversion.cpp"
#include "rangeKutta.cpp"
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
        cout<< "6. Exit\n";


        int op;
        cin >> op;

        if(op==6) break;

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
    
    cout<<"Matrix Inversion \n";
    int sz;
    cout << "Enter the size of the matrix: ";
    cin >> sz;

    vector<vector<double>> matrix(sz, vector<double>(sz));
    cout << "Enter the matrix elements: " << endl;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            cin >> matrix[i][j];
        }
    }
    matrixInversion(matrix);

    cout<<"4th order Range Kutta Method \n";
    cout<<"Enter initial condition y0: ";
    double y0;
    cin>>y0;
    cout<<"Enter Start value  x0: ";
    double x0;
    cin>>x0;
    cout<<"Enter End value x_end: ";
    double x_end;
    cin>>x_end;
    cout<<"Enter step size: ";
    cout<<"Enter step size: ";
    double h;
    cin>>h;
    rangeKutta(y0,x0,x_end,h);
    return 0;
}

/*
For option 1 to 5:
   10   -1    2    1    1   12 
  -1   10   -1    2    1   15 
   2   -1   10   -1    2   16 
   1    2   -1   10   -1   14 
   1    1    2   -1   10   13


   For Inversion:
   10   -1    2    1    1   
  -1   10   -1    2    1    
   2   -1   10   -1    2    
   1    2   -1   10   -1    
   1    1    2   -1   10    


        4 -1 0 1
        -1 3 -1 2
        0 -1 5 3

//For Kutta:
        double y0 = 1.0;      // Initial condition   
        double x0 = 0.0;      // Start value of x
        double x_end = 5.0;   // End value of x
        double h = 0.1;       // Step size
*/