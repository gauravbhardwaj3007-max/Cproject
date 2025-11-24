#include <stdio.h>

int main() {
    int arrInt[3] = {10, 20, 30};
    float arrFloat[3] = {1.1, 2.2, 3.3};
    char arrChar[3] = {'A', 'B', 'C'};

    int *pInt = arrInt;
    float *pFloat = arrFloat;
    char *pChar = arrChar;

    printf("Pointer Arithmetic Demonstration:\n");
    printf("---------------------------------\n");

    // Integer pointer arithmetic
    printf("Initial pInt = %p, *pInt = %d\n", (void*)pInt, *pInt);
    pInt++;
    printf("After pInt++ = %p, *pInt = %d\n", (void*)pInt, *pInt);
    pInt--;
    printf("After pInt-- = %p, *pInt = %d\n\n", (void*)pInt, *pInt);

    // Float pointer arithmetic
    printf("Initial pFloat = %p, *pFloat = %.1f\n", (void*)pFloat, *pFloat);
    pFloat++;
    printf("After pFloat++ = %p, *pFloat = %.1f\n", (void*)pFloat, *pFloat);
    pFloat--;
    printf("After pFloat-- = %p, *pFloat = %.1f\n\n", (void*)pFloat, *pFloat);

    // Char pointer arithmetic
    printf("Initial pChar = %p, *pChar = %c\n", (void*)pChar, *pChar);
    pChar++;
    printf("After pChar++ = %p, *pChar = %c\n", (void*)pChar, *pChar);
    pChar--;
    printf("After pChar-- = %p, *pChar = %c\n", (void*)pChar, *pChar);

    return 0;
}
