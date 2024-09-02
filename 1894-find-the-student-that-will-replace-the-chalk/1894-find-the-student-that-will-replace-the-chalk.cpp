class Solution {
public:
    /**
     * Approach:
     * - First, calculate the total sum of chalk.
     * - Compute the remaining chalk after full rounds by taking `k % sum`.
     * - Iterate through the `chalk` vector and subtract the chalk requirements from the remaining chalk.
     * - When the remaining chalk is less than the current student's requirement, return the index of that student.
     * 
     * Complexity:
     * - Time Complexity: O(n), where `n` is the size of the `chalk` vector.
     * - Space Complexity: O(1)
     */
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        long sum = accumulate(chalk.begin(), chalk.end(), 0L);
        
        int remaining = k % sum;
        
        for(int i = 0 ; i < chalk.size() ; ++i)
        {
            if(remaining < chalk[i])
                return i;
            
            remaining -= chalk[i];
        }
        
        return 0;
    }
};