#include <iostream>
#include <cmath>
#include <iomanip>

// Define the non-linear equation f(x) and transform it into x = g(x)
double g(double x) {
    // Example equation: f(x) = x^3 - 4x - 9, transformed into g(x) = (4x + 9)^(1/3)
    return cbrt(4 * x + 9);  // g(x) = (4x + 9)^(1/3)
}

// Fixed Point Iteration method
void fixedPointIteration(double initialGuess, double tolerance, int maxIter) {
    double x0 = initialGuess;  // Initial guess
    double x1;  // Next approximation
    int iteration = 0;

    // Iterate to find the root using Fixed Point Iteration method
    while (iteration < maxIter) {
        // Calculate the next approximation
        x1 = g(x0);

        // Check for convergence
        if (fabs(x1 - x0) < tolerance) {
            break;
        }

        // Update the guess for the next iteration
        x0 = x1;
        iteration++;
    }

    // Output the results
    std::cout << "Estimated root: " << std::fixed << std::setprecision(6) << x1 << std::endl;
    std::cout << "Functional value at calculated root: " << std::fixed << std::setprecision(6) << g(x1) << std::endl;
    std::cout << "Number of iterations: " << iteration << std::endl;
}

int main() {
    double initialGuess, tolerance;
    int maxIter;

    // Get user input for initial guess, tolerance, and maximum iterations
    std::cout << "Enter the initial guess: ";
    std::cin >> initialGuess;
    std::cout << "Enter the tolerance for convergence: ";
    std::cin >> tolerance;
    std::cout << "Enter the maximum number of iterations: ";
    std::cin >> maxIter;

    // Call the Fixed Point Iteration method function
    fixedPointIteration(initialGuess, tolerance, maxIter);

    return 0;
}

