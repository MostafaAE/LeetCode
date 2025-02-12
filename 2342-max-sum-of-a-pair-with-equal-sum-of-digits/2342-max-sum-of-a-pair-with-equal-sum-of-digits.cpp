class Solution {
public:
    /**
     * Approach:
     * 1. Use an unordered map to group numbers by the sum of their digits.
     *    - The key is the digit sum, and the value is a min-heap (priority queue) to store the two largest numbers with that digit sum.
     * 2. Iterate through the input array:
     *    - Calculate the digit sum of each number.
     *    - Add the number to the corresponding min-heap in the map.
     *    - If the heap size exceeds 2, remove the smallest element to retain the two largest numbers.
     * 3. Iterate through the map to find pairs of numbers with the same digit sum:
     *    - If a digit sum group has exactly two numbers, calculate their sum.
     *    - Track the maximum pair sum across all groups.
     * 4. Return the maximum pair sum, or -1 if no valid pair is found.
     *
     * Complexity:
     * - Time Complexity: O(n * log(m)) = O(n), where `n` is the size of `nums`, and `m` is the maximum number in `nums`.
     *   - Calculating digit sum is O(log(m)).
     *   - Insertion and deletion in a min-heap of size 2 is O(log(2)) = O(1).
     * - Space Complexity: O(logm) for storing numbers in the map.
     **/
    int maximumSum(vector<int>& nums) 
    {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> sumToNumbers;

        // Group numbers by the sum of their digits
        for(int num : nums)
        {
            int digitSum = getNumSum(num);
            sumToNumbers[digitSum].push(num);

            // Maintain only the two largest numbers for each digit sum
            if(sumToNumbers[digitSum].size() > 2)
                sumToNumbers[digitSum].pop();
        }

        int maxPairSum{-1};

        // Calculate the maximum sum of pairs with the same digit sum
        for(auto[sum, minHeap] : sumToNumbers)
        {
            if(minHeap.size() == 2)
            {
                int first = minHeap.top();
                minHeap.pop();
                int second = minHeap.top();
                maxPairSum = max(maxPairSum, first + second);
            }
        }

        return maxPairSum;
    }

private:
    // Helper function to calculate the sum of digits of a number
    int getNumSum(int num)
    {
        int sum{};
        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};