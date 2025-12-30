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

// Bisection method
double bisection(double a, double b, int* iterations) {
    double c, fa, fb, fc;

    printf("\nBisection Method:\n");
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

// Secant method
double secant(double x0, double x1, int* iterations) {
    double x2, f0, f1, f2;

    printf("\nSecant Method:\n");
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

// Newton-Raphson method
double newtonRaphson(double x0, int* iterations) {
    double x1, f0, f1;

    printf("\nNewton-Raphson Method:\n");
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
    double a = 1.0, b = 3.0; // Initial interval for bisection method
    double x0 = 1.0, x1 = 3.0; // Initial guesses for secant method
    double x_initial = 2.0; // Initial guess for Newton-Raphson method
    double root_bisection, root_secant, root_newton;
    int iterations_bisection, iterations_secant, iterations_newton;

    // Bisection method
    root_bisection = bisection(a, b, &iterations_bisection);
    printf("\nRoot (Bisection Method): %.4lf\n", root_bisection);
    printf("Number of iterations: %d\n", iterations_bisection);

    // Secant method
    root_secant = secant(x0, x1, &iterations_secant);
    printf("\nRoot (Secant Method): %.4lf\n", root_secant);
    printf("Number of iterations: %d\n", iterations_secant);

    // Newton-Raphson method
    root_newton = newtonRaphson(x_initial, &iterations_newton);
    printf("\nRoot (Newton-Raphson Method): %.4lf\n", root_newton);
    printf("Number of iterations: %d\n", iterations_newton);

    // Suggestions
    printf("\nSuggestions:\n");
    printf("Bisection Method: Suitable for functions with known sign change in the interval.\n");
    printf("Secant Method: Suitable for finding roots near the initial guesses.\n");
    printf("Newton-Raphson Method: Suitable for fast convergence near the root.\n");

    return 0;
}
