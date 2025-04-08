// complex.cpp: Additionl practice, discuss during office hours
#include <iostream>
#include <cmath>
using namespace std;

class Complex {
public:
    Complex(double re = 0.0, double im = 0.0) : real(re), imag(im) {}  // Parameterized constructor with defaults
    double getReal() const { return real; }
    double getImag() const { return imag; }
    void print() const { cout << real << " + " << imag << "j" << endl; }

// Add operator+ below (non-member)

private:
    double real;
    double imag;
};

int main() {
    Complex x(3.0, 4.0);  // Example: 3 + 4j
    // Step 1: Create three Complex objects (no args, one arg, two args) and print
    // Step 2: Add operator+ above (non-member)
    // Step 3: Test operator+ here—add two objects, try chaining, print results
    return 0;
}