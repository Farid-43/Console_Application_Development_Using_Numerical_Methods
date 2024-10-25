#include <bits/stdc++.h>
using namespace std;

void swapRows(vector<vector<double>>& matrix, int row1, int row2) {
    int n = matrix[0].size();
    for (int i = 0; i < n; i++) {
        swap(matrix[row1][i], matrix[row2][i]);
    }
}

vector<vector<double>> invertMat(const vector<vector<double>>& inputMat) {
    int n = inputMat.size();
    vector<vector<double>> augmentedMat(n, vector<double>(2 * n));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmentedMat[i][j] = inputMat[i][j];
        }
        augmentedMat[i][n + i] = 1.0;
    }

    for (int i = 0; i < n; i++) {
        // Partial pivoting to handle division by zero cases
        if (fabs(augmentedMat[i][i]) < 1e-9) {
            for (int k = i + 1; k < n; k++) {
                if (fabs(augmentedMat[k][i]) > 1e-9) {
                    swapRows(augmentedMat, i, k);
                    break;
                }
            }
        }


        double pivot = augmentedMat[i][i];
        for (int j = 0; j < 2 * n; j++) {
            augmentedMat[i][j] /= pivot;
        }

        // Making all other elements in the current column 0
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = augmentedMat[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    augmentedMat[k][j] -= factor * augmentedMat[i][j];
                }
            }
        }
    }

    vector<vector<double>> invertedMat(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            invertedMat[i][j] = augmentedMat[i][j + n];
        }
    }

    return invertedMat;
}


void printMat(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(10) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int main() {
    int n;
    cout << "Enter the value of n (n*n matrix): ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n));
    cout << "Enter the co-efficients:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<double>> invertedMat = invertMat(matrix);

    cout << "The inverse of the matrix is: " << endl;
    printMat(invertedMat);

    return 0;
}



/*

A=
2 3 2 3 5
3 2 3 4 5
6 7 4 5 3
4 5 2 1 5
2 4 8 9 6

A(inverse) =

 -0.39697   0.466667  0.0878788   0.030303  -0.127273
  0.351515  -0.466667  0.0939394  0.0151515  0.0363636
 -0.706061  0.0666667  -0.175758   0.439394   0.254545
  0.454545 -5.55112e-17   0.181818  -0.454545 -0.0909091
  0.157576  0.0666667  -0.130303  0.0757576 -0.0181818


A=
3 3 1
2 2 1
2 1 3

A(inverse) =
 5 -8  1
-4  7 -1
-2  3  0

*/
