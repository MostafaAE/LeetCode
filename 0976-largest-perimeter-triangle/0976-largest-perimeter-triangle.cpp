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
        sort(nums.begin(), nums.end(), greater<int>()); // sort in descending order
        
        for(int i = 0 ; i < (int)nums.size()-2 ; i++)
        {
            int a = nums[i], b = nums[i+1], c = nums[i+2];

            if(a < b + c)
                return a + b + c;
        }
        
        return 0;
    }
};