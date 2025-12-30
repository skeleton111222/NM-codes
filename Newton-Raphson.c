#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define MAX_ITERATIONS 50

// Function to calculate the equation: log(x) - cos(x)
double equation(double x) {
    return log(x) - cos(x);
}

// Derivative of the equation: 1/x + sin(x)
double derivative(double x) {
    return 1.0 / x + sin(x);
}

// Newton-Raphson method
double newtonRaphson(double x0, int* iterations) {
    double x1, f0, f1;

    printf("%-10s%-12s%-12s%-12s%-12s\n", "Iteration", "x0", "f(x0)", "f'(x0)", "x1");

    for (*iterations = 1; *iterations <= MAX_ITERATIONS; ++(*iterations)) {
        f0 = equation(x0);
        if (fabs(f0) < EPSILON)
            break;

        f1 = derivative(x0);

        x1 = x0 - f0 / f1;

        printf("%-10d%-12.4lf%-12.4lf%-12.4lf%-12.4lf\n",
               *iterations, x0, f0, f1, x1);

        x0 = x1;
    }

    return x1;
}

int main() {
    double x0 = 2.0; // Initial guess for Newton-Raphson method
    double root_newton;
    int iterations;

    // Newton-Raphson method
    root_newton = newtonRaphson(x0, &iterations);

    printf("\nRoot (Newton-Raphson Method): %.4lf\n", root_newton);
    printf("Number of iterations: %d\n", iterations);

    return 0;
}
