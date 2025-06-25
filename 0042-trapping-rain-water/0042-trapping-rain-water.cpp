class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size(), left{}, right{n-1};
        int leftMax{height[0]}, rightMax{height[n-1]};

        int result{};
        while(left < right)
        {
            if(leftMax < rightMax)
            {
                ++left;
                leftMax = max(leftMax, height[left]);
                result += leftMax - height[left];
            }
            else
            {
                --right;
                rightMax = max(rightMax, height[right]);
                result += rightMax - height[right];
            }
        }
        
        return result;
    }
};