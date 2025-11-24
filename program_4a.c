#include <stdio.h>

int main() {
    int x = 10;
    float y = 3.14;
    char z = 'A';

    // Declare pointers
    int *pInt = &x;
    float *pFloat = &y;
    char *pChar = &z;

    printf("Pointer Demonstration:\n");
    printf("-----------------------\n");

    // Integer pointer
    printf("x = %d, &x = %p\n", x, (void*)&x);
    printf("pInt (address stored) = %p, *pInt (value) = %d\n\n", (void*)pInt, *pInt);

    // Float pointer
    printf("y = %.2f, &y = %p\n", y, (void*)&y);
    printf("pFloat (address stored) = %p, *pFloat (value) = %.2f\n\n", (void*)pFloat, *pFloat);

    // Char pointer
    printf("z = %c, &z = %p\n", z, (void*)&z);
    printf("pChar (address stored) = %p, *pChar (value) = %c\n", (void*)pChar, *pChar);

    return 0;
}
