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
    int trap(vector<int>& height) {
        int left{}, right{(int) height.size() - 1}, curHeight{}, water{};
        
        while(left < right)
        {
            if(height[left] < curHeight)
                water += curHeight - height[left];
            if(height[right] < curHeight)
                water += curHeight - height[right];
            
            curHeight = max(curHeight, min(height[left], height[right]));
            
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        
        return water;
    }
};