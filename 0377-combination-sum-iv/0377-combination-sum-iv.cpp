const int MAX = 1000 + 1;
int memory[MAX];
vector<int> numsg;

class Solution {
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     * 
     * Counting DP
     *
     * Complexity:
     * Time Complexity : O(MN) 
     * Space Complexity : O(M) where M is the max target, and N is the max index
     */
    int combinationSum4(vector<int>& nums, int target) 
    {
        memset(memory, -1 , sizeof(memory));
        numsg = nums;
        return combSum(target);
    }
    
    int combSum(int remaining)
    {
        // not valid
        if(remaining < 0)
            return 0;
        
        // valid way
        if(remaining == 0)
            return 1;
        
        int &ret = memory[remaining];
        if(ret != -1)
            return ret;
        
        ret = 0;
        for(int i = 0 ; i < (int)numsg.size() ; i++)
            ret += combSum(remaining - numsg[i]);
    
        return ret;
    }
};