#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define MAX_ITERATIONS 50

// Function to calculate the equation: log(x) - cos(x)
double equation(double x) {
    return log(x) - cos(x);
}

// Bisection method
double bisection(double a, double b, int* iterations) {
    double c, fa, fb, fc;

    printf("%-10s%-12s%-12s%-12s%-12s%-12s%-12s\n", "Iteration", "a", "b", "c", "f(a)", "f(b)", "f(c)");

    for (*iterations = 1; *iterations <= MAX_ITERATIONS; ++(*iterations)) {
        c = (a + b) / 2;
        fa = equation(a);
        fb = equation(b);
        fc = equation(c);

        printf("%-10d%-12.4lf%-12.4lf%-12.4lf%-12.4lf%-12.4lf%-12.4lf\n",
               *iterations, a, b, c, fa, fb, fc);

        if (fc == 0.0 || fabs(b - a) < EPSILON)
            break;
        else if (fc * fa < 0)
            b = c;
        else
            a = c;
    }

    return c;
}

int main() {
    double a = 1.0, b = 3.0; // Initial interval for bisection method
    double root_bisection;
    int iterations;

    // Bisection method
    root_bisection = bisection(a, b, &iterations);

    printf("\nRoot (Bisection Method): %.4lf\n", root_bisection);
    printf("Number of iterations: %d\n", iterations);

    return 0;
}
