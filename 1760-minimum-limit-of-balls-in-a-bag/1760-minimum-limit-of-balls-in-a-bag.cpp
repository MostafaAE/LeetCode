class Solution {
public:
    /**
     * Approach:
     * 1. Use binary search to find the minimum possible value of the maximum ball size (`num`) that can satisfy the operations limit.
     * 2. Define `start` as `1` (minimum possible size) and `end` as the maximum element in `nums`.
     * 3. Perform binary search:
     *    - Calculate the mid-point value (`mid`) and check if it's possible to divide all numbers in `nums` into sizes no greater than `mid` using at most `maxOperations`.
     *    - If possible, update `result` to `mid` and search in the lower half (`end = mid - 1`).
     *    - Otherwise, search in the upper half (`start = mid + 1`).
     * 4. The helper function `checkNumOfOperations` calculates the number of operations required to split the elements into sizes no greater than `num`:
     *    - For each element in `nums`, the number of splits needed is `ceil(nums[i] / num) - 1`.
     *    - If the total operations exceed `maxOperations`, return `false`; otherwise, return `true`.
     * 
     * Complexity:
     * Time Complexity: O(n * log(k))
     * - O(log(k)) for binary search, where `k` is the largest number in `nums`.
     * - O(n) for each check in `checkNumOfOperations`.
     * Space Complexity: O(1)
     */
    int minimumSize(vector<int>& nums, int maxOperations) 
    {        
        int start{1}, result{};
        int end = *max_element(nums.begin(), nums.end());

        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            
            if(checkNumOfOperations(nums, mid, maxOperations))
            {
                result = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        
        return result;
    }
    
    int checkNumOfOperations(vector<int>& nums, int num, int maxOperations)
    {
        int n = nums.size(), count{};
        
        for(int i = 0 ; i < n ; ++i)
        {
            count += ceil((double)nums[i] / num) - 1;
            
            if(count > maxOperations)
                return false;
        }
        
        return true;
    }
};