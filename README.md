
# Console Application Development Using Numerical Methods

A console application that implements various
numerical methods. 


### 1. Solution of Linear Equations
   - **Jacobi Iterative Method**
   - **Gauss-Seidel Iterative Method**
   - **Gauss Elimination**
   - **Gauss-Jordan Elimination**
   - **LU Factorization**

### 2. Solution of Non-linear Equations
   - **Bi-section Method**
   - **False Position Method**
   - **Secant Method**
   - **Newton-Raphson Method**

### 3. Solution of Differential Equations
   - **Runge-Kutta Method**

### 4. Matrix Inversion

## Deployment

#### To deploy this project run

```bash
  git clone https://github.com/Farid-43/Console_Application_Development_Using_Numerical_Methods.git
```

#### To run the project
Run main.cpp file

## Explanation
### 1. Solution of Linear Equations
   - **Jacobi Iterative Method**
     - **Description**: It Solves linear equations by iterating and updating each variable based on the previous estimates of other variables.
     - **Implementation**: After ensuring the matrix is diagonally dominant, the method updates all variables simultaneously for each iteration until the solution converges.
     - **Pseudocode**:
       1. Ensuring matrix `A` is diagonally dominant.
       2. Initializing `x_old` with initial guesses.
       3. Repeating until convergence:
          ```plaintext
          For each variable i:
              x_new[i] = (b[i] - Σ(A[i][j] * x_old[j])) / A[i][i] for j ≠ i
          Updated x_old = x_new.
          ```

   - **Gauss-Seidel Iterative Method**
     - **Description**: An improvement on the Jacobi method, this approach updates variables sequentially using the latest available values, leading to faster convergence.
     - **Implementation**: Similar to Jacobi, with sequential updates for faster solution convergence, and includes a diagonally dominant matrix rearrangement.
     - **Pseudocode**:
       1. Ensuring matrix `A` is diagonally dominant.
       2. Initializing `x` with initial guesses.
       3. Repeating until convergence:
          ```plaintext
          For each variable i:
              x[i] = (b[i] - Σ(A[i][j] * x[j])) / A[i][i] for j < i
          Using updated x values immediately.
          ```

   - **Gauss Elimination**
     - **Description**: Transforms the matrix into an upper triangular form, allowing for back-substitution to solve the system.
     - **Implementation**: Using row operations, this method eliminates coefficients below the main diagonal. A helper function then performs back-substitution to solve for each variable.
     - **Pseudocode**:
       1. For each row `i`, making `A[i][i]` the largest entry in its column (pivoting).
       2. For rows below `i`, eliminating elements in column `i`:
          ```plaintext
          A[j] = A[j] - (A[j][i] / A[i][i]) * A[i]
          ```
       3. Performing back-substitution from the last row upwards to solve for `x`.

   - **Gauss-Jordan Elimination**
     - **Description**: It extends Gauss elimination by reducing the matrix to row echelon form, allowing direct reading of solutions without back-substitution.
     - **Implementation**: Using row operations to produce a reduced row echelon form of the matrix, allowing direct reading of variable values.
     - **Pseudocode**:
       1. For each row `i`, making `A[i][i]` the largest entry in its column (pivoting).
       2. For each row `j ≠ i`, eliminating elements in column `i`:
          ```plaintext
          A[j] = A[j] - (A[j][i] / A[i][i]) * A[i]
          ```
       3. Solution `x` is directly readed from the transformed matrix.

   - **LU Factorization**
     - **Description**: Decomposes the matrix into lower (L) and upper (U) triangular matrices, solving the system with forward and backward substitution.
     - **Implementation**: The matrix is decomposed into `L` and `U` matrices, and the system is solved by first solving `Ly = b` and then `Ux = y`.
     - **Pseudocode**:
       1. Decompose `A` into `L` (lower triangular) and `U` (upper triangular).
       2. Solving `Ly = b` using forward substitution.
       3. Solving `Ux = y` using back substitution to find `x`.