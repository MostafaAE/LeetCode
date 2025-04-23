/**
 * Approach:
 * 1. We are tasked with counting how many numbers in the range 1 to `n` belong to the largest group based on their digit sum.
 * 2. The first step is to compute the digit sum for each number from 1 to `n`. For example, for 12, the digit sum is 1 + 2 = 3.
 * 3. Group numbers by their digit sums using a hash map `groupToSize`. The key is the digit sum and the value is the frequency (or size) of that group.
 * 4. Track the largest group size (`largestGroupSize`) and how many groups have that size (`largestGroupCount`).
 * 5. For each number:
 *    - Compute its digit sum.
 *    - Update the count of that group.
 *    - Compare the group's size to `largestGroupSize` and update `largestGroupCount` accordingly.
 * 6. Finally, return the number of groups that have the largest size.
 * 
 * Time Complexity:
 * - O(n * logn), where `n` is the input number.
 * 
 * Space Complexity:
 * - O(logn), for storing the group sizes in `groupToSize` hash map.
 */
class Solution {
public:
    int countLargestGroup(int n) 
    {
        int largestGroupSize{}, largestGroupCount{};
        unordered_map<int, int> groupToSize;
        
        for(int val = 1 ; val <= n ; ++val)
        {
            // Calculate the sum of digits for the current number
            int group = sumDigits(val);

            // Update the size of the group
            ++groupToSize[group];

            // Get the current group size
            int currentGroupSize = groupToSize[group];

            // Update largest group count based on the group size
            if(currentGroupSize == largestGroupSize)
            {
                ++largestGroupCount;
            }
            else if(currentGroupSize > largestGroupSize)
            {
                largestGroupCount = 1;
                largestGroupSize = currentGroupSize;
            }
        }

        return largestGroupCount;
    }

private:

    // Helper function to calculate the sum of digits of a number
    int sumDigits(int num)
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
