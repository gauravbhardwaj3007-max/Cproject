#include <stdio.h>

int FIBO(int num) {
    // Base cases:
    // The 0th Fibonacci number is 0
    if (num == 0) {
        return 0;
    }
    // The 1st Fibonacci number is 1
    else if (num == 1) {
        return 1;
    }
    // Recursive case:
    // F(n) = F(n-1) + F(n-2)
    else {
        return FIBO(num - 1) + FIBO(num - 2);
    }
}

int main() {
    int num_terms, i;

    printf("Enter the number of terms for the Fibonacci sequence: ");
    scanf("%d", &num_terms);

    // Validate input
    if (num_terms < 0) {
        printf("Please enter a non-negative number of terms.\n");
    } else {
        printf("Fibonacci sequence up to %d terms:\n", num_terms);
        for (i = 0; i < num_terms; i++) {
            printf("%d ", FIBO(i));
        }
        printf("\n");
    }

    return 0;
}