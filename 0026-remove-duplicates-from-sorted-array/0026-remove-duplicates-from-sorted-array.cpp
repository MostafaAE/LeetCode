class Solution {
public:
    /* 
    * Approach:
    * Two pointers technique
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int removeDuplicates(vector<int>& nums) {
        
        int left{1};
        for(int right = 1; right < (int)nums.size() ; right++)
            if(nums[right] != nums[right-1])
                nums[left++] = nums[right]; 

        return left;
    }
};