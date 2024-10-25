
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
```bash
Run main.cpp file
```
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


### 2.Solution of Non-Linear Equation Solvers

## Bisection Method
- **Description**: The Bisection method is a root-finding method that repeatedly divides an interval in half to narrow down the potential location of a root. It requires the function to change signs over the interval \([a,b]\).
- **Implementation**: The method checks the function values at the endpoints of the interval and finds the midpoint. If the function value at the midpoint is sufficiently close to zero, it returns the midpoint as the root. Otherwise, it narrows the interval to the half where a sign change occurs.
- **Pseudocode**:
  1. Initializing \( a \) and \( b \) with the endpoints of the interval.
  2. While the absolute difference between \( a \) and \( b \) is greater than tolerance:
     ```plaintext
     Calculating the midpoint mid = (a + b) / 2.
     If f(mid) == 0, return mid.
     If f(a) * f(mid) < 0, set b = mid.
     Else set a = mid.
     ```
  3. Return mid as the root.

## False Position Method
- **Description**: The False Position method is a root-finding method that combines features of the Bisection method and linear interpolation.
- **Implementation**: Similar to the Bisection method, it starts with two points and checks the function values. It uses linear interpolation to find a better approximation of the root, adjusting the interval based on the sign of the function.
- **Pseudocode**:
  1. Initializing \( a \) and \( b \) with the endpoints of the interval.
  2. While the function value at mid is not sufficiently close to zero:
     ```plaintext
     Calculating mid using linear interpolation: mid = (a * f(b) - b * f(a)) / (f(b) - f(a)).
     If f(mid) == 0, return mid.
     If f(a) * f(mid) < 0, set b = mid.
     Else set a = mid.
     ```
  3. Return mid as the root.

## Newton-Raphson Method
- **Description**: The Newton-Raphson method is an iterative technique that uses the derivative of a function to find its roots.
- **Implementation**: Starting with an initial guess, it updates the guess using the formula 
\[
x = x - \frac{f(x)}{f'(x)}
\]. This process is repeated until the approximation converges to a root.
- **Pseudocode**:
  1. Initializing \( x \) with an initial guess.
  2. While the absolute value of the function at \( x \) is greater than tolerance:
     ```plaintext
     Calculating the derivative f'(x).
     Update x using x = x - f(x) / f'(x).
     ```
  3. Return \( x \) as the root.

## Secant Method
- **Description**: The Secant method is a numerical technique to find roots of functions using two initial approximations and does not require the derivative.
- **Implementation**: It approximates the derivative using the values of the function at the two initial points and iteratively refines the guesses.
- **Pseudocode**:
  1. Initializing \( x_1 \) and \( x_2 \) with two initial guesses.
  2. While the absolute value of the function at \( x_3 \) is greater than tolerance:
     ```plaintext
     Calculating x3 = x2 - (f(x2) * (x2 - x1)) / (f(x2) - f(x1)).
     Update x1 and x2 for the next iteration.
     ```
  3. Return \( x_3 \) as the root.
