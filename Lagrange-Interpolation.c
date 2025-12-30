#include <stdio.h>

// Lagrange Interpolation Function
double lagrangeInterpolation(int n, double x[], double y[], double xi) {
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term = term * (xi - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    // Given Data Set
    double x[] = {4, 5, 7, 10, 11, 13};
    double y[] = {48, 100, 294, 900, 1210, 2028};

    // Points to find
    double xi1 = 8;   // Find f(8)
    double xi2 = 15;  // Find f(15)

    // Calculate interpolated values
    double result1 = lagrangeInterpolation(6, x, y, xi1);
    double result2 = lagrangeInterpolation(6, x, y, xi2);

    // Display the results
    printf("f(%0.2lf) = %0.2lf\n", xi1, result1);
    printf("f(%0.2lf) = %0.2lf\n", xi2, result2);

    return 0;
}

