#include <iostream>
#include <cmath>
#include <iomanip>


double f(double x) {
  
    return x*x*x - 4*x - 9;
}


double f_derivative(double x) {
   
    return 3*x*x - 4;
}


void newtonRaphson(double initialGuess, double tolerance, int maxIter) {
    double x0 = initialGuess;
    double x1;
    int iteration = 0;

    
    while (iteration < maxIter) {
      
        x1 = x0 - f(x0) / f_derivative(x0);

       
        if (fabs(x1 - x0) < tolerance) {
            break;
        }

       
        x0 = x1;
        iteration++;
    }

  
    std::cout << "Estimated root: " << std::fixed << std::setprecision(6) << x1 << std::endl;
    std::cout << "Functional value at calculated root: " << std::fixed << std::setprecision(6) << f(x1) << std::endl;
    std::cout << "Number of iterations: " << iteration << std::endl;
}

int main() {
    double initialGuess, tolerance;
    int maxIter;

    // Get user input
    std::cout << "Enter the initial guess: ";
    std::cin >> initialGuess;
    std::cout << "Enter the tolerance for convergence: ";
    std::cin >> tolerance;
    std::cout << "Enter the maximum number of iterations: ";
    std::cin >> maxIter;

    // Call the Newton-Raphson method
    newtonRaphson(initialGuess, tolerance, maxIter);

    return 0;
}

