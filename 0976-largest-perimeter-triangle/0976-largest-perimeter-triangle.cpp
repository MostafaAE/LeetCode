class Solution {
public:
    
    /* 
    * Approach:
    * sort the array and return the sum of the largest 3 values (largest perimeter)
    * which can form a valid triangle
    * 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(1)
    */
    int largestPerimeter(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end(), greater<int>());
        
        for(int i = 0 ; i < (int)nums.size()-2 ; i++)
        {
            int a = nums[i], b = nums[i+1], c = nums[i+2];
            if(checkValidity(a, b, c))
                return a + b + c;
        }
        
        return 0;
    }
    
    // function to check if three sides form a triangle or not
    bool checkValidity(int a, int b, int c)
    {
        // check condition
        if (a + b <= c || a + c <= b || b + c <= a)
            return false;
        else
            return true;
    }
};