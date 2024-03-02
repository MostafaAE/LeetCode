class Solution {
public:
    /* 
    * Approach: 
    * When we square the array it will be partitioned into two sorted arrays (non-increasing from left) and (non-increasing from right), so we can use two pointers to merge these two arrays in O(n).
    Two pointers technique
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1) => ignoring the output space
    */
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n{(int)nums.size()}, right{n-1}, left{}, i{n-1};
        vector<int> result(n);
        
        while(left <= right)
        {
            if(abs(nums[right]) >= abs(nums[left]))
                result[i] = nums[right]*nums[right--];
            else
                result[i] = nums[left]*nums[left++];
            
            i--;
        }
        
        return result;
    }
};