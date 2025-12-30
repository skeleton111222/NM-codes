#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define MAX_ITERATIONS 50

// Function to calculate the equation: log(x) - cos(x)
double equation(double x) {
    return log(x) - cos(x);
}

// Secant method
double secant(double x0, double x1, int* iterations) {
    double x2, f0, f1, f2;

    printf("%-10s%-12s%-12s%-12s%-12s%-12s%-12s\n", "Iteration", "x0", "x1", "x2", "f(x0)", "f(x1)", "f(x2)");

    for (*iterations = 1; *iterations <= MAX_ITERATIONS; ++(*iterations)) {
        f0 = equation(x0);
        f1 = equation(x1);
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        f2 = equation(x2);

        printf("%-10d%-12.4lf%-12.4lf%-12.4lf%-12.4lf%-12.4lf%-12.4lf\n",
               *iterations, x0, x1, x2, f0, f1, f2);

        if (fabs(f2) < EPSILON)
            break;

        x0 = x1;
        x1 = x2;
    }

    return x2;
}

int main() {
    double x0 = 1.0, x1 = 3.0; // Initial guesses for secant method
    double root_secant;
    int iterations;

    // Secant method
    root_secant = secant(x0, x1, &iterations);

    printf("\nRoot (Secant Method): %.4lf\n", root_secant);
    printf("Number of iterations: %d\n", iterations);

    return 0;
}
