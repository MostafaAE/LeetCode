class Solution {
public:
    /*
     * Approach:
     * - Count frequency of digits in input.
     * - Check each 3-digit even number (100 to 998).
     * - For each, ensure digit frequency is within available limits.
     *
     * Complexity:
     * - Time: O(n + 450) ≈ O(n)
     * - Space: O(1) excluding result.
     */
    vector<int> findEvenNumbers(vector<int>& digits) 
    {
        vector<int> digitFreq(10, 0);

        // O(n)
        for (int digit : digits)
            digitFreq[digit]++;

        vector<int> result;
        
        // O(450)
        for (int num = 100; num <= 998; num += 2)
        {
            vector<int> requiredFreq(10, 0);
            int val = num;

            // Build digit count for current number
            while(val > 0)
            {
                int d = val % 10;
                val /= 10;
                requiredFreq[d]++;
            }

            // Compare against available digit frequencies
            bool valid = true;
            for (int d = 0; d <= 9; ++d)
            {
                if (requiredFreq[d] > digitFreq[d])
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
                result.push_back(num);
        }

        return result;
    }
};