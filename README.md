
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

### To deploy this project run

```bash
  git clone https://github.com/Farid-43/Console_Application_Development_Using_Numerical_Methods.git
```

### To run the project
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


## 2.Solution of Non-Linear Equation Solvers

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
x = x - frac{f(x)}/{f'(x)}
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


## 3.Solution of Differential Equations

### Runge-Kutta 4th Order Method

- **Description**: The function `f` represents the differential equation \( y' = f(x, y) \) that we aim to solve.
- **Implementation**: In this example, the function `f` is defined as \( f(x, y) = x - y \), meaning the equation is \( y' = x - y \).
- **Pseudocode**:
  1. Define `f(x, y)`.
     ```plaintext
     return x - y
  2. Calculate the intermediate `k` values:
   ```plaintext
   k1 = h * f(x_n, y_n)
   k2 = h * f(x_n + h / 2, y_n + k1 / 2)
   k3 = h * f(x_n + h / 2, y_n + k2 / 2)
   k4 = h * f(x_n + h, y_n + k3)
   y_n = y_n + (k1 + 2 * k2 + 2 * k3 + k4) / 6

## 4.Matrix Inversion

- **Description**: Matrix inversion is the process of finding a matrix, called the inverse, which, when multiplied by the original matrix, results in an identity matrix. This process is commonly used in solving systems of linear equations, as it transforms the original matrix into a form where solutions can be directly read.

- **Implementation**: To find the inverse, we used an augmented matrix approach with Gaussian elimination. The matrix is augmented by appending an identity matrix, and row operations are applied to transform the original matrix into an identity matrix, with the identity matrix transforming into the inverse.

- **Pseudocode**:
  1. **Initializing Augmented Matrix**: Creating an augmented matrix by appending an identity matrix to the original matrix.
  
  2. **Pivoting and Row Operations**:
     - For each row \( i \):
       1. **Pivot Check**: If the diagonal element is near zero, swap with a row below where the element in the same column is non-zero.
       2. **Normalize Row**: Dividing all elements in row \( i \) by the diagonal element to make it 1.
       3. **Eliminate Other Rows**: For each row \( k \):
          - Subtract a multiple of row \( i \) from row \( k \) to make the element in the current column zero.
  
  3. **Extract Inverse Matrix**: After all rows have been processed, the right half of the augmented matrix will contain the inverse.


## Lessons Learned
Throughout our journey in developing the Console Application Using Numerical Methods, we gained invaluable experience, particularly in using GitHub effectively. This was a major project and becoming familiar with GitHub helped streamline our collaboration and code management.

As we progressed through the project, we encountered various challenges, especially with merging codes and files. These obstacles required us to adapt and learn from different resources, whether through documentation, tutorials, or discussions with peers. Each challenge provided us with an opportunity to deepen our understanding of both the numerical methods and the tools we were using.

Additionally, we discovered the importance of thorough testing and debugging, which played a critical role in ensuring the accuracy and reliability of our application. By actively engaging with each other and leveraging our collective knowledge, we were able to overcome these hurdles and successfully complete our project.

This project not only enhanced our technical skills but also taught us the value of collaboration, problem-solving, and continuous learning.

## Group Members

- [Sumaiya Akter](https://github.com/sa-hcc5142)
- [Akash Biswas](https://github.com/akash07013)
- [Farid Ahmed](https://github.com/Farid-43)


## Feedback

If you have any feedback, please reach out to us at
    [Farid Ahmed](faridpatwary2020@gmail.com)

