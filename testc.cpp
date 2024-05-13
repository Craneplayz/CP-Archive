#include <stdio.h>
#include <string.h>

const int N = 500001;
int primes[N], iPrime = 0;
bool sieve[N];

void generatePrimes() {
    memset(sieve, 1, sizeof sieve);
    sieve[1] = 0;
    for (int i = 2; i < N; i++)
        for (int j = i; sieve[i] && j < N; j += i)
            if (i == j)
                primes[iPrime++] = i;
            else
                sieve[j] = 0;
}

int main() {
    generatePrimes();

    int n;
    scanf("%d", &n);

    for (int k = 6; k <= n; k += 2)
        for (int i = 0; i < iPrime && primes[i] <= k; i++)
            if (sieve[k - primes[i]]) {
                printf("%d=%d+%d\n", k, primes[i], k - primes[i]);
                break;
            }

    return 0;
}