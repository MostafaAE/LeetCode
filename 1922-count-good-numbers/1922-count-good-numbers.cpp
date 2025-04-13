class Solution {
private:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp, int mod) 
    {
        long long result = 1;
        base %= mod;
        while (exp > 0) 
        {
            if (exp % 2 == 1)
                result = (result * base) % mod;

            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

public:
    int countGoodNumbers(long long n) 
    {
        long long evenCount = (n + 1) / 2;  // Even indices: 0, 2, 4, ...
        long long primeCount = n / 2;       // Odd indices: 1, 3, 5, ...
        
        long long evenWays = modPow(5, evenCount, MOD);
        long long primeWays = modPow(4, primeCount, MOD);
        
        return (evenWays * primeWays) % MOD;
    }
};
