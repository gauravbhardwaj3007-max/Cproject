#include <stdio.h>

int main() {
    unsigned int num, shift;

    printf("Enter a number: ");
    scanf("%u", &num);

    printf("Enter number of positions to shift: ");
    scanf("%u", &shift);

    printf("\nShift Operations:\n");
    printf("-----------------\n");

    // Left shift
    printf("%u << %u = %u\n", num, shift, (num << shift));

    // Right shift
    printf("%u >> %u = %u\n", num, shift, (num >> shift));

    return 0;
}
