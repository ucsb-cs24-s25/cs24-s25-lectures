// complex.cpp: Additionl practice, discuss during office hours
#include <iostream>
#include <cmath>
using namespace std;
// a + bj,  j = sqrt(-1)
class Complex {
public:
    Complex(double re = 0.0, double im = 0.0) {  
        data = new double[2];
        data[0] = re;  
        data[1] = im;
    }
    double getReal() const { return data[0]; }
    double getImag() const { return data[1]; }
    void setReal(double re) { data[0] = re; } 
    void print() const { 
        cout << data[0] << " + " 
             << data[1] << "j" << endl; 
    }
    //Destructor
    ~Complex();
    //Copy constructor
    Complex(const Complex& other);
    void operator=(const Complex& other);

private:
    double* data; // point to the actual
};

Complex::~Complex(){
    // cout << "Bbye object at location:" << this 
    //      << " is going away\n";
    // cout << "Data: \n";
    // print();
    delete [] data;
}
// Complex y = x;
// Complex y(x);

Complex::Complex(const Complex& other){
    // y is the implicit object
    data = new double[2];
    data[0] = other.data[0];
    data[1] = other.data[1];
}
// y = x;
void Complex::operator=(const Complex& other){
        data[0] = other.data[0];
        data[1] = other.data[1];
}


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