// complex.cpp: Additionl practice, discuss during office hours
#include <iostream>
#include <cmath>
using namespace std;

class Complex {
public:
    Complex(double re = 0.0, double im = 0.0) {  
        real = re;  
        imag = im;
    }
    double getReal() const { return real; }
    double getImag() const { return imag; }
    void setReal(double re) { real = re; } 
    void print() const { 
        cout << real << " + " 
             << imag << "j" << endl; 
    }
 
private:
    double real;
    double imag; 
};

int foo() {
    Complex x(3.0, 4.0);
    Complex y = x;  // Default copy constructor
    y.setReal(5.0);
    x.print();      // ?
    y.print();      // ?
    return 0;
}  // Objects destroyed here

int main() {
    foo();
    return 0;
}