const int MAX = 100 + 1;
int memory[MAX];
vector<int> numsg;
class Solution {
public:
    /* 
    * Approach:
    * Dynamic Programming Memoization (Pick or Leave approach)
    * 
    * Complexity:
    * Time Complexity : O(N)
    * Space Complexity : O(N)
    */
    int rob(vector<int>& nums) 
    {
        numsg = nums;
        memset(memory, -1, sizeof(memory));
        return robHouses(0);
    }
    
    int robHouses(int idx)
    {
        // reached the end
        if(idx >= (int)numsg.size())
            return 0;
        
        int &ret = memory[idx];
        if(ret != -1)
            return ret;
        
        int rob = numsg[idx] + robHouses(idx + 2);
        int leave = robHouses(idx + 1);
        
        return ret = max(rob, leave);
    }
};