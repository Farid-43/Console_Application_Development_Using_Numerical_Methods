#include<bits/stdc++.h>
using namespace std;

const int maxIterations = 10000;
const int tolerance = .00001;

void makeDiagonallyDominant(vector<vector<double>>& A, vector<double>& b) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                sum += fabs(A[i][j]);
            }
        }

        if (fabs(A[i][i]) < sum) {
            for (int k = i + 1; k < n; k++) {
                double newSum = 0.0;
                for (int j = 0; j < n; j++) {
                    if (k != j) {
                        newSum += fabs(A[k][j]);
                    }
                }
                if (fabs(A[k][k]) >= newSum) {
                    swap(A[i], A[k]);
                    swap(b[i], b[k]);
                    break;
                }
            }
        } 
    }
}

void jacobiMethod(vector<vector<double>>& A, vector<double>& b) {
    int n = A.size();

    makeDiagonallyDominant(A, b);

    vector<double> x(n,0.0);
    vector<double> x_new(n);
    
    for (int iteration = 0; iteration < maxIterations; iteration++) {

        for (int i = 0; i < n; i++) {
            double sum = 0.0;

            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }

        vector<double> error(n);
        for (int i = 0; i < n; i++) {
            error[i] = fabs(x_new[i] - x[i]);
        }

        if (error[0] < tolerance && error[1] < tolerance && error[2]<tolerance) {
            x = x_new;
            return;
        }
        x = x_new;
    }

    cout<<"The solution is: ";
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;

}

void gaussSeidelMethod(vector<vector<double>>& A,vector<double>& b) {
    int n = A.size();

    makeDiagonallyDominant(A,b);

    vector<double> x(n,0.0);
    vector<double> x_new(n);

    for (int iteration = 0; iteration < maxIterations; iteration++) {

        for (int i = 0; i < n; i++){
            double sum = 0.0;

            for (int j = 0; j < i; j++) {
                sum += A[i][j] * x_new[j];
            }

            for (int j = i + 1; j < n; j++) {
                sum += A[i][j] * x[j];
            }

            x_new[i] = (b[i] - sum) / A[i][i];
        }
       
        vector<double> error(n);
        for (int i = 0; i < n; i++) {
            error[i]= fabs(x_new[i] - x[i]);
        }

        if (error[0] < tolerance && error[1] < tolerance && error[2] < tolerance) {
            x = x_new;
            return;
        } 
        x = x_new;
    }

    cout<<"The solution is: ";
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;


}

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

void luDecomposition(vector<vector<double>>& A,vector<double> &b) {
    
    int n=A.size();
    vector<vector<double>> L(n, vector<double>(n, 0));
    vector<vector<double>> U(n, vector<double>(n, 0));

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

    vector<double> x = luSolve(L, U, b);

    cout << "The solution is: ";
    for (double val : x) {
        cout << val << " ";
    }
    cout << endl;

}

void printMat(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cout << setw(10) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void swapRows(vector<vector<double>>& matrix, int row1, int row2) {
    int n = matrix.size();
    for (int i = 0; i <= n; i++) {
        swap(matrix[row1][i], matrix[row2][i]);
    }
}

vector<vector<double>> gaussEli(vector<vector<double>> matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        if (fabs(matrix[i][i]) < 1e-9) {
            for (int k = i + 1; k < n; k++) {
                if (fabs(matrix[k][i]) > 1e-9) {
                    swapRows(matrix, i, k);
                    break;
                }
            }
        }
        for (int j = i + 1; j < n; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = 0; k <= n; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
    return matrix;
}

vector<double> backSubs(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    vector<double> soln(n);
    for (int i = n - 1; i >= 0; i--) {
        soln[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++) {
            soln[i] -= matrix[i][j] * soln[j];
        }
        soln[i] /= matrix[i][i];
    }
    return soln;
}

vector<vector<double>> gaussJorEli(vector<vector<double>> matrix) {
    int n = matrix.size();
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = 0; k <= n; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
    return matrix;
}

vector<vector<double>> rowEche(vector<vector<double>> matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        if (fabs(matrix[i][i]) < 1e-9) {
            for (int k = i + 1; k < n; k++) {
                if (fabs(matrix[k][i]) > 1e-9) {
                    swapRows(matrix, i, k);
                    break;
                }
            }
        }
        double pivot = matrix[i][i];
        if (fabs(pivot) > 1e-9) {
            for (int j = i; j <= n; j++) {
                matrix[i][j] /= pivot;
            }
        }
        for (int k = i + 1; k < n; k++) {
            double factor = matrix[k][i];
            for (int j = i; j <= n; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
    return matrix;
}

void gaussElinmination(vector<vector<double>> matrix) {
    cout << "Performing Gauss Elimination:" << endl;
    vector<vector<double>> matrix2 = gaussEli(matrix);
    matrix2 = rowEche(matrix2);
    printMat(matrix2);

    vector<double> solution = backSubs(matrix2);
    cout << "The solutions of the system of linear equations are:" << endl;
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }
}

void gaussJorElimination(vector<vector<double>> matrix) {
    cout << "Performing Gauss-Jordan Elimination:" << endl;
    vector<vector<double>> matrix2 = gaussEli(matrix);
    vector<vector<double>> matrix3 = gaussJorEli(matrix2);
    matrix3 = rowEche(matrix3);
    printMat(matrix3);

    cout << "The solutions of the system of linear equations are:" << endl;
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << matrix3[i][n] << endl;
    }
}


