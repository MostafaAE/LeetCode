const int MAX = 2*10000 + 1;
int memory[MAX];
vector<int> numsg;
class Solution {
public:
    
    /* 
    * Approach:
    * Dynamic Programming Memoization (Pick next bit mask approach)
    * 
    * Complexity:
    * Time Complexity : O(N^2)
    * Space Complexity : O(N)
    */
    int deleteAndEarn(vector<int>& nums) 
    {
        memset(memory, -1, sizeof(memory));
        sort(nums.begin(), nums.end());
        numsg = nums;
        numsg.insert(numsg.begin(), 2*MAX);
        
        return deleteEarn(0) - 2*MAX;
    }
    
    int deleteEarn(int idx)
    {
        if(idx >= (int)numsg.size())
            return 0;
        
        int &ret = memory[idx];
        if(ret != -1)
            return ret;
        
        ret = 0;
        for(int j = idx + 1 ; j < (int)numsg.size() ; j++)
        {
            // delete this value
            if(numsg[j] != numsg[idx] + 1)
                ret = max(ret, deleteEarn(j));
        }
        
        ret += numsg[idx];

        return ret;
    }
};