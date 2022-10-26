class Solution {
public:
    /* 
    * Approach:
    * for each pair of sides search for the valid third side values using lower_bound
    * and count them
    * 
    * Complexity:
    * Time Complexity : O(n^2logn)
    * Space Complexity : O(1)
    */
    int triangleNumber(vector<int>& nums) 
    {
        int numOfTriplets{};
        int size {(int)nums.size()};
        sort(nums.begin(), nums.end());
        
        for(int i = 0 ; i < size-2 ; i++)
        {
            for (int j = i+1 ; j < size-1 ; j++)
            {
                int validThirdSide = nums[i] + nums[j];
                auto itr = lower_bound(nums.begin(), nums.end(), validThirdSide);
                
                int d = distance(nums.begin(), itr)-1;
                if(d > j)
                    numOfTriplets += d - j;
            }
        }
        
        return numOfTriplets;
    }
};