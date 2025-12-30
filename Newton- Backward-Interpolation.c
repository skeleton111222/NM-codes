#include <stdio.h>

// Function to calculate the backward difference table
void calculateBackwardDifferenceTable(int n, double x[], double y[], double diffTable[][n]) {
    // Initialize the first column of the difference table with y values
    for (int i = 0; i < n; i++) {
        diffTable[i][0] = y[i];
    }

    // Calculate the backward difference table
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            diffTable[i][j] = diffTable[i][j - 1] - diffTable[i - 1][j - 1];
        }
    }
}

// Function to display the backward difference table
void displayDifferenceTable(int n, double x[], double diffTable[][n]) {
    printf("Backward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%-4.2lf", x[i]);
        for (int j = 0; j <= i; j++) {
            printf("\t%-4.2lf", diffTable[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Newton's Backward Interpolation
double newtonBackwardInterpolation(int n, double x[], double y[], double diffTable[][n], double xi) {
    double result = y[n - 1];
    double term = 1;

    printf("\nNewton's Backward Interpolation Formula:\n");
    printf("f(x) = %.2lf", result);

    for (int i = n - 2; i >= 0; i--) {
        term *= (xi - x[i + 1]) / (x[i] - x[i + 1]);
        result += term * diffTable[i][n - i - 2];

        printf(" + %.2lf * ", term);
        printf("(%.2lf - %.2lf)", xi, x[i + 1]);
    }
    printf("\n");

    return result;
}

int main() {
    // Given data
    double x[] = {45, 50, 55, 60, 65};
    double y[] = {114.84, 96.16, 83.32, 74.48, 68.48};
    int n = sizeof(x) / sizeof(x[0]);

    // Value to estimate
    double xi = 63;

    // Create a 2D array for the backward difference table
    double diffTable[n][n];

    // Calculate the backward difference table
    calculateBackwardDifferenceTable(n, x, y, diffTable);

    // Display the backward difference table
    displayDifferenceTable(n, x, diffTable);

    // Perform Newton's Backward Interpolation to estimate the premium at age 63
    double result = newtonBackwardInterpolation(n, x, y, diffTable, xi);

    // Display the result
    printf("\nEstimated premium for policy maturity at age %.2lf: %.2lf RS\n", xi, result);

    return 0;
