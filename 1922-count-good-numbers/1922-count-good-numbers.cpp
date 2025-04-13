class Solution {
private:
    const int MOD = 1e9 + 7;

    /**
     * Computes (base^exp) % mod using fast exponentiation.
     */
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
    /**
    * Approach:
    * - We ned to count the number of good numbers of length `n` such that:
    *   - Even indices (0-based) must be digits that are even (0, 2, 4, 6, 8) => 5 choices.
    *   - Odd indices must be prime digits (2, 3, 5, 7) => 4 choices.
    * 
    * - So the total number of valid combinations is:
    *     5^(#even_indices) * 4^(#odd_indices)
    * 
    * - Number of even indices = (n + 1) / 2 (since index 0 is even).
    * - Number of odd indices = n / 2
    * 
    * - Use fast modular exponentiation (`modPow`) to calculate both terms efficiently.
    * 
    * Time Complexity:
    * - O(log n), because we use fast exponentiation for powers.
    * 
    * Space Complexity:
    * - O(1), constant space is used.
    */
    int countGoodNumbers(long long n) 
    {
        long long evenCount = (n + 1) / 2;  // Even indices: 0, 2, 4, ...
        long long primeCount = n / 2;       // Odd indices: 1, 3, 5, ...
        
        long long evenWays = modPow(5, evenCount, MOD);   // 5 options for each even index
        long long primeWays = modPow(4, primeCount, MOD); // 4 options for each odd index
        
        return (evenWays * primeWays) % MOD;
    }
};
