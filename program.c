#include <stdio.h>

int main() {
    int n, sum = 0;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        sum += i;  // Add each term to sum
    }

    printf("Sum of the series up to %d terms is: %d\n", n, sum);

    return 0;
}
