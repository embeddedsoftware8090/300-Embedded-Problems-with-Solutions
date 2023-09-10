#include <stdio.h>

// Structure to represent a complex number
struct Complex {
    double real;     // Real part
    double imaginary; // Imaginary part
};

// Function to add two complex numbers
struct Complex add(struct Complex a, struct Complex b) {
    struct Complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

// Function to subtract two complex numbers
struct Complex subtract(struct Complex a, struct Complex b) {
    struct Complex result;
    result.real = a.real - b.real;
    result.imaginary = a.imaginary - b.imaginary;
    return result;
}

// Function to multiply two complex numbers
struct Complex multiply(struct Complex a, struct Complex b) {
    struct Complex result;
    result.real = a.real * b.real - a.imaginary * b.imaginary;
    result.imaginary = a.real * b.imaginary + a.imaginary * b.real;
    return result;
}

// Function to divide two complex numbers
struct Complex divide(struct Complex a, struct Complex b) {
    struct Complex result;
    double denominator = b.real * b.real + b.imaginary * b.imaginary;
    result.real = (a.real * b.real + a.imaginary * b.imaginary) / denominator;
    result.imaginary = (a.imaginary * b.real - a.real * b.imaginary) / denominator;
    return result;
}

// Function to print a complex number
void printComplex(struct Complex num) {
    if (num.imaginary >= 0) {
        printf("%.2lf + %.2lfi\n", num.real, num.imaginary);
    } else {
        printf("%.2lf - %.2lfi\n", num.real, -num.imaginary);
    }
}

int main() {
    struct Complex complex1 = {4.0, 5.0};
    struct Complex complex2 = {2.0, 3.0};

    struct Complex sum = add(complex1, complex2);
    printf("Sum: ");
    printComplex(sum);

    struct Complex difference = subtract(complex1, complex2);
    printf("Difference: ");
    printComplex(difference);

    struct Complex product = multiply(complex1, complex2);
    printf("Product: ");
    printComplex(product);

    struct Complex quotient = divide(complex1, complex2);
    printf("Quotient: ");
    printComplex(quotient);

    return 0;
}
