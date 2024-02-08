class Solution {
public:
    /* 
    * Approach: 
    * Fix two numbers so we are left with the two-sum problem at hand which we can solve using Two pointers or hashtable.
    *
    * Complexity:
    * Time Complexity : O(n^3)
    * Space Complexity : O(n) 
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n{(int)nums.size()};
        vector<vector<int>> result;
        set<vector<int>> unique;
        sort(nums.begin(), nums.end());
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i + 1 ; j < n ; j++)
            {
                int left{j + 1}, right{n-1};
                long long twoSum = nums[i] + nums[j];
                while(left < right)
                {
                    long long sum = twoSum + nums[left] + nums[right];
                    
                    if(sum == target)
                    {
                        if(unique.insert({nums[i], nums[j], nums[left], nums[right]}).second)
                            result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    }
                    else if (sum < target)
                        left++;
                    else
                        right--;
                }
            }
        }
        return result;
    }
};