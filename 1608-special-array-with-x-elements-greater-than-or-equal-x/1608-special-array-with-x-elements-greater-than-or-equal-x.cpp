class Solution {
public:
    /*
    * Approach:
    * - Sort the array `nums` in ascending order.
    * - Iterate through the sorted array to determine the value of `x` such that exactly `x` numbers in the array are greater than or equal to `x`.
    * - For each element in the sorted array, check if the remaining number of elements is equal to or greater than the current element.
    * - If the above condition holds, and if `x` (the remaining number of elements) is not greater than the previous element, return `x`.
    * - If no such `x` is found, return -1.
    *
    * Complexity:
    * - Time Complexity: O(n logn)
    * - Space Complexity: O(1)
    */
    int specialArray(vector<int>& nums) 
    {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0 ; i < nums.size() ; ++i, --len)
        {
            if(len <= nums[i])
            {
                if(i > 0 && len <= nums[i - 1])
                    break;
                else
                    return len;
            }
        }
        return -1;
    }
};