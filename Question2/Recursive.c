#include <stdio.h>

int recursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    return recursive(n - 3) + recursive(n - 2);
}

int main() {
    int n = 10; // Example value of n
    printf("Fib(%d) = %d\n", n, recursive(n));
    return 0;
}

