class Solution {
public:
    /**
     * Approach:
     * - Use the Sieve of Eratosthenes to precompute prime numbers up to right (upper range).
     * - Extract prime numbers within the given range `[left, right]`.
     * - Find the two consecutive prime numbers with the smallest difference.
     * - Return these two numbers; if no such pair exists, return `{-1, -1}`.
     *
     * Complexity Analysis:
     * - Time Complexity: O(R log log R) + O(R - L)
     *      - Sieve of Eratosthenes: O(R log log R)
     *      - Extracting primes in range and finding the closest prime pair: O(R - L) (iterating over `[left, right]`)
     * - Space Complexity: O(R) for storing the sieve.
     */
    vector<int> closestPrimes(int left, int right) 
    {
        vector<int> primeNumbers = getPrimeNumbersInRange(left, right);

        int n = primeNumbers.size();

        int diff{INT_MAX};
        vector<int> result(2, -1);
        
        // Find the closest prime pair
        for(int i = 1 ; i < n ; ++i)
        {
            int curDiff = primeNumbers[i] - primeNumbers[i - 1];
            if(curDiff < diff)
            {
                diff = curDiff;
                result[0] = primeNumbers[i - 1];
                result[1] = primeNumbers[i];
            }
        }

        return result;
    }

    vector<int> getPrimeNumbersInRange(int left, int right)
    {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;

        // Sieve of Eratosthenes to precompute prime numbers
        for(int i = 2 ; i * i <= right ; ++i)
        {
            if(isPrime[i])
            {
                for(int j = i * i ; j <= right ; j += i)
                    isPrime[j] = false;
            }
        }

        // Collect prime numbers within the range
        vector<int> primeNumbers;
        for(int i = left ; i <= right ; ++i)
        {
            if(isPrime[i])
            {
                primeNumbers.push_back(i);
            }
        }

        return primeNumbers;
    }
};
