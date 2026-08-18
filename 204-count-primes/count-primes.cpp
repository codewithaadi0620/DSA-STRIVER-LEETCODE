class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        // Only store odd numbers
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        // 2 is the only even prime
        int cnt = 1;

        // Only odd i
        for (int i = 3; 1LL * i * i < n; i += 2) {

            if (isPrime[i]) {

                // Only odd multiples
                for (int j = i * i; j < n; j += 2 * i) {
                    isPrime[j] = false;
                }
            }
        }

        // Count remaining odd primes
        for (int i = 3; i < n; i += 2) {
            if (isPrime[i])
                cnt++;
        }

        return cnt;
    }
};