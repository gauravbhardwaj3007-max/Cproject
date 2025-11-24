#include <stdio.h>

// Recursive function to calculate factorial
long long int fact_recursive(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact_recursive(n - 1);
    }
}

// Non-recursive function to calculate factorial
long long int fact_non_recursive(int n) {
    long long int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate binomial coefficient C(n, r)
long long int binomial_coefficient(int n, int r) {
    if (r < 0 || r > n) {
        return 0; // Invalid input for binomial coefficient
    }
    // Using the recursive factorial function for calculation
    return fact_recursive(n) / (fact_recursive(r) * fact_recursive(n - r));
}

int main() {
    printf("Computing Binomial Coefficients C(n, r)\n");
    printf("---------------------------------------\n");
    printf("n\tr\tC(n,r)\t\t(Using fact_recursive)\n");
    printf("---------------------------------------\n");

    // Tabulate results for different values of n and r
    for (int n_val = 0; n_val <= 5; n_val++) {
        for (int r_val = 0; r_val <= n_val; r_val++) {
            long long int result = binomial_coefficient(n_val, r_val);
            printf("%d\t%d\t%lld\n", n_val, r_val, result);
        }
    }

    printf("\nDemonstrating both factorial functions:\n");
    printf("---------------------------------------\n");
    int test_num = 5;
    printf("Factorial of %d (Recursive): %lld\n", test_num, fact_recursive(test_num));
    printf("Factorial of %d (Non-Recursive): %lld\n", test_num, fact_non_recursive(test_num));

    return 0;
}