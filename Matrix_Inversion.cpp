#include <bits/stdc++.h>
using namespace std;


void printInverse(const vector<vector<double>>& inverse) {
    cout << "Inverse Matrix:" << endl;
    int n = inverse.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(10) << inverse[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printOriginal(const vector<vector<double>>& matrix) {
    cout << "Original Matrix:" << endl;
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(10) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void swaprows(vector<vector<double>>& matrix, int row1, int row2) {
    int n = matrix.size();
    for (int i = 0; i < 2 * n; i++) {
        swap(matrix[row1][i], matrix[row2][i]);
    }
}

void matrixInversion(vector<vector<double>> matrix) {
    printOriginal(matrix);
    int n = matrix.size();
    vector<vector<double>> augmented(n, vector<double>(2 * n, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmented[i][j] = matrix[i][j];
        }
        augmented[i][i + n] = 1.0;
    }

    for (int i = 0; i < n; i++) {
        if (fabs(augmented[i][i]) < 1e-9) {
            for (int k = i + 1; k < n; k++) {
                if (fabs(augmented[k][i]) > 1e-9) {
                    swaprows(augmented, i, k);
                    break;
                }
            }
        }
        
        double pivot = augmented[i][i];
        for (int j = 0; j < 2 * n; j++) {
            augmented[i][j] /= pivot;
        }

        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = augmented[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    augmented[k][j] -= factor * augmented[i][j];
                }
            }
        }
    }

    vector<vector<double>> inverse(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = augmented[i][j + n];
        }
    }
    printInverse(inverse);
}



