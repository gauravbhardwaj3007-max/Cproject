#include <stdio.h>

// Function to check if a number is prime
int ISPRIME(int num) {
    if (num <= 1)
        return 0;  // 0 and 1 are not prime
    
    for (int i = 2; i * i <= num; i++) { // check up to sqrt(num)
        if (num % i == 0)
            return 0;  // Not prime
    }
    return 1;  // Prime
}

int main() {
    int lower, upper;

    // Input range
    printf("Enter the lower limit: ");
    scanf("%d", &lower);
    printf("Enter the upper limit: ");
    scanf("%d", &upper);

    printf("Prime numbers between %d and %d are:\n", lower, upper);

    // Generate prime numbers in range
    for (int i = lower; i <= upper; i++) {
        if (ISPRIME(i))
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}
