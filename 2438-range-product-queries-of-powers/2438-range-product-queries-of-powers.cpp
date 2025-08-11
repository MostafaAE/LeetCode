/*
Approach:
1. Decompose `n` into powers of 2:
   - Starting from 2^29 (highest possible within constraints), check if it can be subtracted from `n`.
   - If yes, store it in the `powers` array and subtract it from `n`.
   - Continue until `n` becomes zero.
   - Reverse the array so powers are in ascending order.
   
2. Answer each query:
   - For each query [left, right], multiply the powers in that range modulo (1e9+7).
   - Push the result to the output vector.

Time Complexity: O(q logn)
- Step 1 (building powers): O(log n) → at most 30 iterations.
- Step 2 (answering queries): O(q * P) where q = number of queries, P = average range length.
- Worst-case: O(q * log n).

Space Complexity: O(log n) for storing the powers array.
*/

class Solution
{
private:
    const int MOD = 1e9 + 7;

public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) 
    {
        vector<int> powers;

        // Start from the highest power of 2 ≤ 2^29
        int power = pow(2, 29);

        // Decompose n into powers of 2
        while (n > 0)
        {
            if (n >= power)
            {
                powers.push_back(power);
                n -= power;
            }
            power /= 2;
        }

        // Reverse so that powers are in ascending order
        reverse(powers.begin(), powers.end());

        vector<int> result;
        
        for (auto &query : queries)
        {
            int left = query[0], right = query[1];
            long long res = 1;
            
            // Multiply powers in the range [left, right]
            for (int i = left; i <= right; ++i)
            {
                res = (res * powers[i]) % MOD;
            }
            
            result.push_back(res);
        }

        return result;
    }
};