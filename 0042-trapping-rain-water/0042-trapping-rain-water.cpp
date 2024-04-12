class Solution {
public:
    /* 
    * Approach: 
    * Two pointers technique.
    * We can also solve it using two arrays (left prefix max, right suffix max), so we can get the max left and max right for each index but will be O(n) memory.
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1) 
    */
    int trap(vector<int>& height) {
        int left{}, right{(int)height.size() - 1}, res{};
        int leftMax{height[left]}, rightMax{height[right]};
        
        while(left < right)
        {
            if(leftMax < rightMax)
            {
                ++left;
                leftMax = max(leftMax, height[left]);
                res += leftMax - height[left];
            }
            else
            {
                --right;
                rightMax = max(rightMax, height[right]);
                res += rightMax - height[right];
            }
        }
        
        return res;
    }
};