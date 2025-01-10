#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double g(double x) {
    return cbrt(4 * x + 9);
}

void fixedPointIteration(double initialGuess, double tolerance, int maxIter) {
    double x0 = initialGuess;
    double x1;
    int iteration = 0;

    while (iteration < maxIter) {
        x1 = g(x0);

        if (fabs(x1 - x0) < tolerance) {
            break;
        }

        x0 = x1;
        iteration++;
    }

    cout << "Estimated root: " << fixed << setprecision(6) << x1 << endl;
    cout << "Functional value at calculated root: " << fixed << setprecision(6) << g(x1) << endl;
    cout << "Number of iterations: " << iteration << endl;
}

int main() {
    double initialGuess, tolerance;
    int maxIter;

    cout << "Enter the initial guess: ";
    cin >> initialGuess;
    cout << "Enter the tolerance for convergence: ";
    cin >> tolerance;
    cout << "Enter the maximum number of iterations: ";
    cin >> maxIter;

    fixedPointIteration(initialGuess, tolerance, maxIter);

    return 0;
}

