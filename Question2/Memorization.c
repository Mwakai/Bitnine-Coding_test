#include <stdio.h>

int memo[1000]; // Adjust the size as needed

int memoization(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    if (memo[n] != -1) return memo[n];

    memo[n] = memoization(n - 3) + memoization(n - 2);
    return memo[n];
}

int main() {
    int n = 10; // Example value of n

    // Initialize memoization array
    for (int i = 0; i < 1000; i++) {
        memo[i] = -1;
    }

    printf("F(%d) = %d\n", n, memoization(n));
    return 0;
}

