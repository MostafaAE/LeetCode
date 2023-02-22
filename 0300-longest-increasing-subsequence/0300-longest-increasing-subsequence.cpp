class Solution {
private:
const static int MAX = 2500 + 1;
int memory[MAX];
    
public:
    /*
     * Approach:
     * Dynamic Programming Tabulation
     *
     * Complexity:
     * Time Complexity : O(N^2)
     * Space Complexity : O(N) where N is the max index
     */
    int lengthOfLIS(vector<int>& nums) 
    {
        memset(memory, -1, sizeof(memory));
        return LIS(nums);
    } 
    
    int LIS(vector<int>& nums)
    {
        nums.push_back(INT_MAX);

        // base case
        memory[0] = 1;

        for (int i = 1; i < (int)nums.size(); i++)
        {
            int &ret = memory[i];
            ret = 1;
            for (int j = i - 1; j >= 0; j--)
                if (nums[j] < nums[i])
                    ret = max(ret, 1 + memory[j]);
        }

        return memory[nums.size() - 1] - 1;
    }
};
