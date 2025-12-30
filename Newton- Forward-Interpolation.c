#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to perform Newton's Forward Interpolation
void newtonForwardInterpolation(int n, double x[], double y[][n], double value) {
    double result = 0;
    double term;

    // Calculate differences
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    // Perform interpolation
    result = y[0][0];
    term = 1.0;

    for (int i = 1; i < n; i++) {
        term *= (value - x[i - 1]) / (i * 1.0);
        result += term * y[0][i];
    }

    // Display the result
    printf("Interpolated value at x = %.2lf: %.4lf\n", value, result);
}

int main() {
    int n = 5; // Number of data points
    double x[] = {0, 1, 2, 3, 4}; // x values
    double y[][5] = {
        {1, 2, 4, 8, 16},  // y values
        {0}};

    double value = 2.5; // Value for interpolation

    // Perform Newton's Forward Interpolation
    newtonForwardInterpolation(n, x, y, value);

    return 0;
}
