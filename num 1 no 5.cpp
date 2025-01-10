#include <iostream>
#include <vector>

using namespace std;

double hornerMethod(const vector<double>& coefficients, double x) {
    double result = coefficients[0];
    for (size_t i = 1; i < coefficients.size(); ++i) {
        result = result * x + coefficients[i];
    }
    return result;
}

int main() {
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    vector<double> coefficients(degree + 1);
    cout << "Enter the coefficients of the polynomial (from highest to lowest degree): " << endl;
    for (int i = 0; i <= degree; ++i) {
        cin >> coefficients[i];
    }

    double x;
    cout << "Enter the value of x: ";
    cin >> x;

    double result = hornerMethod(coefficients, x);
    cout << "The result of the polynomial evaluation is: " << result << endl;

    return 0;
}

