class Solution {
public:
    /*
     * Approach:
     * This is a variant of Linked List Cycle II Problem
     * Use a slow and fast pointer to find the intersection point (where they meet), then move the head and the intersection 1 step until they meet.
     *
     * Another solution: Use a hash table to check if a number is repeated O(n) memory.
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(n)
     */
    int findDuplicate(vector<int>& nums) 
    {
        int intersection = getIntersection(nums);
        
        int head{0};
        
        while(head != intersection)
        {
            head = nums[head];
            intersection = nums[intersection];
        }
        
        return intersection;
    }
    
    int getIntersection(vector<int>& nums)
    {
        int slow{0}, fast{0};
        
        while(true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            
            if(nums[slow] == nums[fast])
                return slow;
        }
        
        return -1;
    }
};