class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                markMultiplesAsNonPrime(isPrime, i, n);
            }
        }

        return count(isPrime.begin(), isPrime.end(), true);
    }

private:
    void markMultiplesAsNonPrime(vector<bool>& isPrime, int prime, int n) {
        for (int i = prime * prime; i < n; i += prime) {
            isPrime[i] = false;
        }
    }
};
