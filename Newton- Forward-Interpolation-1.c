#include <stdio.h>
#include <math.h>

// Function to calculate the forward difference table
void calculateForwardDifferenceTable(int n, double x[], double y[], double diffTable[][n]) {
    // Initialize the first column of the difference table with y values
    for (int i = 0; i < n; i++) {
        diffTable[i][0] = y[i];
    }

    // Calculate the forward difference table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diffTable[i][j] = diffTable[i + 1][j - 1] - diffTable[i][j - 1];
        }
    }
}

// Function to display the forward difference table
void displayDifferenceTable(int n, double x[], double diffTable[][n]) {
    printf("Forward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%-4.2lf", x[i]);
        for (int j = 0; j < n - i; j++) {
            printf("\t%-4.5lf", diffTable[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Newton's Forward Interpolation
double newtonForwardInterpolation(int n, double x[], double y[], double diffTable[][n], double xi) {
    double result = y[0];
    double term = 1;
    double factor = (xi - x[0]) / (x[1] - x[0]);

    printf("\nNewton's Forward Interpolation Formula:\n");
    printf("f(x) = %.5lf", result);

    for (int i = 1; i < n; i++) {
        term *= factor / i;
        result += term * diffTable[0][i];

        printf(" + %.5lf * ", term);
        printf("(%.2lf - %.2lf)", factor, x[0]); // Display the factor for each term
    }
    printf("\n");

    return result;
}

int main() {
    // Given data
    double x[] = {20, 25, 30, 35, 40, 45};
    double y[] = {1.30103, 1.39794, 1.47712, 1.54407, 1.60206, 1.65321};
    int n = sizeof(x) / sizeof(x[0]);

    // Value to estimate
    double xi = 23;

    // Calculate the forward difference table
    double diffTable[n][n];
    calculateForwardDifferenceTable(n, x, y, diffTable);

    // Display the forward difference table
    displayDifferenceTable(n, x, diffTable);

    // Perform Newton's Forward Interpolation to estimate the value of Log10(23)
    double result = newtonForwardInterpolation(n, x, y, diffTable, xi);

    // Compare with the exact value
    double exactValue = log10(xi);
    printf("\nExact value of log10(23): %.5lf\n", exactValue);

    // Display the result
    printf("\nEstimated value using Newton's Forward Interpolation: %.5lf\n", result);

    return 0;
}
