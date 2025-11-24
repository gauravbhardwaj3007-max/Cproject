#include <stdio.h>

// Define the structure for a complex number
typedef struct complex {
    float real;
    float imag;
} complex;

// Function to read a complex number from the user
void read_complex(complex *c) {
    printf("Enter the real part: ");
    scanf("%f", &c->real);
    printf("Enter the imaginary part: ");
    scanf("%f", &c->imag);
}

// Function to display a complex number
void display_complex(complex c) {
    printf("Complex number: %.2f + %.2fi\n", c.real, c.imag);
}

// Function to add two complex numbers
complex add_complex(complex c1, complex c2) {
    complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

// Function to subtract two complex numbers
complex subtract_complex(complex c1, complex c2) {
    complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    return result;
}

int main() {
    complex num1, num2, sum, difference;

    printf("--- Reading First Complex Number ---\n");
    read_complex(&num1); // Read the first complex number
    display_complex(num1); // Display the first complex number

    printf("\n--- Reading Second Complex Number ---\n");
    read_complex(&num2); // Read the second complex number
    display_complex(num2); // Display the second complex number

    // Perform and display addition
    sum = add_complex(num1, num2);
    printf("\n--- Addition ---\n");
    printf("Sum: %.2f + %.2fi\n", sum.real, sum.imag);

    // Perform and display subtraction
    difference = subtract_complex(num1, num2);
    printf("\n--- Subtraction ---\n");
    printf("Difference: %.2f + %.2fi\n", difference.real, difference.imag);

    return 0;
}
