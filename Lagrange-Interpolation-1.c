#include <stdio.h>

// Lagrange Interpolation Function same for calculations table 


double lagrangeInterpolation(int n, double x[], double y[], double xi) {
    double result = 0.0;

    printf("Lagrange Interpolation Polynomial:\n");
    for (int i = 0; i < n; i++) {
        double term = y[i];
        printf("L%d(x) = ", i);

        for (int j = 0; j < n; j++) {
            if (j != i) {
                printf("(x - %0.2lf) / (%0.2lf - %0.2lf)", x[j], x[i], x[j]);

                if (j < n - 1) {
                    printf(" * ");
                }

                term *= (xi - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;

        printf("\n");
    }

    return result;
}

int main() {
    // Given Data Set
    double x[] = {4, 5, 7, 10, 11, 13};
    double y[] = {48, 100, 294, 900, 1210, 2028};

    // Point to find
    double xi = x;   // Find f(8)

    // Calculate interpolated value
    double result = lagrangeInterpolation(6, x, y, xi);

    // Display the result
    printf("\nf(%0.2lf) = %0.2lf\n", xi=x, result);

    return 0;
}

