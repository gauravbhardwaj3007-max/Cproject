#include <stdio.h>

// Function that modifies values using pointers
void modifyValues(int *a, float *b, char *c) {
    *a = *a + 10;   // modify integer
    *b = *b * 2;    // modify float
    *c = *c + 1;    // modify char (next ASCII character)
}

int main() {
    int x = 5;
    float y = 3.5;
    char z = 'A';

    printf("Before function call:\n");
    printf("x = %d, y = %.2f, z = %c\n\n", x, y, z);

    // Passing variables by reference (using pointers)
    modifyValues(&x, &y, &z);

    printf("After function call:\n");
    printf("x = %d, y = %.2f, z = %c\n", x, y, z);

    return 0;
}
