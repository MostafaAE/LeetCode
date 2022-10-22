class Solution {
public:
    /* 
    * Approach:
    * copy the array and sort it, then find the leftmost and rightmost elements from the unsorted
    * continious subarray and return the distance between them
    * 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(n)
    */
    int findUnsortedSubarray(vector<int>& nums) 
    {
        vector<int> sorted (nums);
        // O(nlogn)
        sort(sorted.begin(), sorted.end());
        int start{-1}, end{}, size{(int)nums.size()};
        
        // find the first element in the unsorted continuous subarray
        // O(n)
        for(int i = 0 ; i < size ; i++)
        {
            if(nums[i] != sorted[i])
            {
                start = i;
                break;
            }
        }
        
        // find the last element in the unsorted continuous subarray
        // O(n)
        for(int i = size-1 ; i >= 0 ; i--)
        {
            if(nums[i] != sorted[i])
            {
                end = i;
                break;
            }
        }
        if(start == -1)
            return 0;
        
        return end - start + 1;
        
    }
};