/**
 * Approach:
 * - We're asked to count the number of "ideal arrays" of length `n` with values up to `maxValue`.
 * - An ideal array is one where each next element is divisible by the previous one.
 *
 * - Any such array can be represented by a sequence of multiplicative steps using prime factors.
 * - For a value `x`, its prime factorization can be written as: x = p1^e1 * p2^e2 * ...
 * - When x is fixed at the end of the array, we can build the array by distributing these exponents over the array length.
 * - This becomes a combinatorics problem: 
 *     - For each prime exponent `e`, we distribute it over `n` positions (with repetition and order irrelevant).
 *     - The number of such combinations is C(n + e - 1, e)
 *
 * - So for each value `x` from 1 to maxValue:
 *     - Prime factorize x
 *     - For each exponent `e` in the factorization, calculate C(n + e - 1, e)
 *     - Multiply all combinations to get the number of ideal arrays ending in `x`
 *
 * - Use a sieve to precompute prime factorizations and Pascal's Triangle for binomial coefficients.
 *
 */

const int MOD = 1e9 + 7, MAX_N = 1e4 + 10, MAX_P = 15;

int c[MAX_N + MAX_P][MAX_P + 1];  // Binomial coefficients
vector<int> ps[MAX_N];           // Prime factor exponent counts
int sieve[MAX_N];                // Smallest prime factor for each number

class Solution {
public:
    Solution() 
    {
        if (c[0][0]) return;  // Skip if already initialized

        // Sieve to compute smallest prime factors
        for (int i = 2; i < MAX_N; i++) 
        {
            if (sieve[i] == 0) 
            {
                for (int j = i; j < MAX_N; j += i) 
                {
                    sieve[j] = i;
                }
            }
        }

        // Precompute prime exponent counts for each number
        for (int i = 2; i < MAX_N; i++) 
        {
            int x = i;
            while (x > 1) 
            {
                int p = sieve[x], cnt = 0;
                while (x % p == 0) 
                {
                    x /= p;
                    cnt++;
                }
                ps[i].push_back(cnt);
            }
        }

        // Precompute binomial coefficients C(n, k)
        c[0][0] = 1;
        for (int i = 1; i < MAX_N + MAX_P; i++) 
        {
            c[i][0] = 1;
            for (int j = 1; j <= min(i, MAX_P); j++) 
            {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
            }
        }
    }

    int idealArrays(int n, int maxValue) 
    {
        long long ans = 0;

        for (int x = 1; x <= maxValue; x++) 
        {
            long long ways = 1;

            // Multiply ways to distribute each prime exponent over n positions
            for (int p : ps[x]) 
            {
                ways = (ways * c[n + p - 1][p]) % MOD;
            }

            ans = (ans + ways) % MOD;
        }

        return static_cast<int>(ans);
    }
};
