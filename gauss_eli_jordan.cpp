#include <bits/stdc++.h>
using namespace std;

// function to print the matrix
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

// Function to swap two rows of the matrix
void swapRows(vector<vector<double>>& matrix, int row1, int row2) {
    int n = matrix.size();
    for (int i = 0; i <= n; i++) {
        swap(matrix[row1][i], matrix[row2][i]);
    }
}

// Gauss Elimination function to get the Upper Triangular Matrix
vector<vector<double>> gaussEli(vector<vector<double>> matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        // Partial pivoting
        if (fabs(matrix[i][i]) < 1e-9) {
            for (int k = i + 1; k < n; k++) {
                if (fabs(matrix[k][i]) > 1e-9) {
                    swapRows(matrix, i, k);
                    break;
                }
            }
        }

        // Eliminating below the pivot
        for (int j = i + 1; j < n; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = 0; k <= n; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
    return matrix;
}

// Gauss-Jordan Elimination function to get a matrix which is both Upper and Lower Triangular Matrix but not identity matrix yet
vector<vector<double>> gaussJorEli(vector<vector<double>> matrix) {
    int n = matrix.size();

    // Applying elimination to make both upper and lower triangular
    for (int i = n - 1; i >= 0; i--) {
        // No normalization step here, only elimination above the pivot
        for (int j = i - 1; j >= 0; j--) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = 0; k <= n; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
    return matrix;
}

// Row Echelon form (Reduced Matrix)
vector<vector<double>> rowEche(vector<vector<double>> matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        // Partial pivoting
        if (fabs(matrix[i][i]) < 1e-9) {
            for (int k = i + 1; k < n; k++) {
                if (fabs(matrix[k][i]) > 1e-9) {
                    swapRows(matrix, i, k);
                    break;
                }
            }
        }

        // Normalizing the pivot row
        double pivot = matrix[i][i];
        if (fabs(pivot) > 1e-9) {
            for (int j = i; j <= n; j++) {
                matrix[i][j] /= pivot;
            }
        }

        // Eliminating below the pivot
        for (int k = i + 1; k < n; k++) {
            double factor = matrix[k][i];
            for (int j = i; j <= n; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
    return matrix;
}

int main() {
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n + 1));
    cout << "Enter the augmented matrix (coefficients and constants):";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<double>> matrix2 = matrix;
    vector<vector<double>> matrix3;

    cout << "Initial Augmented Matrix: "<<endl;
    printMat(matrix);

    while (true) {
        int op;
        cout << "1. Gauss Elimination \n2. Gauss-Jordan Elimination \n3. Identity Matrix(Solution) \n4. Exit "<<endl;
        cout<<"Enter Option :";
        cin >> op;

        if (op == 1) {
            // Performing Gauss Elimination followed by row Echelon to get the Upper Triangular Matrix
            cout << "Performing Gauss Elimination :" << endl;
            matrix2 = gaussEli(matrix);
            matrix2 = rowEche(matrix2);
            printMat(matrix2);

        } else if (op == 2) {
            // Performing Gauss Elimination followed by Gauss-Jordan Elimination
            cout << "Performing Gauss-Jordan Elimination: " << endl;
            matrix2 = gaussEli(matrix);
            matrix3 = gaussJorEli(matrix2);
            printMat(matrix3);

        } else if (op == 3) {
            // Applying Row Echelon on the matrix obtained from Gauss-Jordan Elimination
            cout << "Identity Matrix (Solution): " << endl;
            matrix3 = rowEche(matrix3);
            printMat(matrix3);



        } else {
            break;
        }
    }
     // Displaying solutions
            cout << "The solutions are: " << endl;
            for (int i = 0; i < n; i++) {
                cout << "x" << i + 1 << " = " << matrix3[i][n] << endl;
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
