class Solution {
public:
    /* 
    * Approach: 
    * Two pointers approach, set one pointer to the left and one to the right of the array, move the pointer that points to the lower line.
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int maxArea(vector<int>& height) 
    {
        int left{}, right{(int)height.size()-1};
        int maxWater{};
        while(left < right)
        {
            int curWater = (right - left)*min(height[left], height[right]);
            maxWater = max(maxWater, curWater);
            
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        
        return maxWater;
    }
};