#include <bits/stdc++.h>
using namespace std;

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

void gaussElinSol(vector<vector<double>> matrix) {
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

void gaussJorElinSol(vector<vector<double>> matrix) {
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

int main() {
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n + 1));
    cout << "Enter the augmented matrix (coefficients and constants):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Initial Augmented Matrix:" << endl;
    printMat(matrix);

    while(1){
    int op;
    cout << "1. Gauss Elimination \n2. Gauss-Jordan Elimination \n3.Exit " << endl;
    cout << "Enter Option: ";
    cin >> op;

    if (op == 1) {
        gaussElinSol(matrix);
    } else if (op == 2) {
        gaussJorElinSol(matrix);
    } else {
       break;
    }

    }

    return 0;
}



/*

5 2 3 2
6 4 3 9
1 5 4 7

x1= 0.560976
x2= 3.21951
x3= -2.41463


2 3 2 3 5 10
3 2 3 4 5 34
6 7 4 5 3 42
4 5 2 1 5 24
2 4 8 9 6 74

x1= 6.89697
x2=-5.35152
x3=17.20606
x4= -5.45455
x5=-1.15758

*/
