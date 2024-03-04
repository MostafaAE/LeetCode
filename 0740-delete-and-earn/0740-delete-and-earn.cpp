class Solution {
private:
    static const int MAX = 2*10000 + 1;
    int memory[MAX];
    vector<int> numsg;
    unordered_map<int, int> freq;
public:
    
    /* 
    * Approach:
    * Dynamic Programming Memoization (Pick or leave approach)
    * 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(n)
    */
    int deleteAndEarn(vector<int>& nums) 
    {
        memset(memory, -1, sizeof(memory));
        
        // Count the frequency of each value
        for(auto val : nums)
            freq[val]++;
        
        // Remove duplicates and sort the array
        set<int> s( nums.begin(), nums.end() );
        numsg.assign( s.begin(), s.end() );
        
        return deleteEarn(0);
    }
    
    int deleteEarn(int idx)
    {
        if(idx >= (int)numsg.size())
            return 0;
        
        int &ret = memory[idx];
        if(ret != -1)
            return ret;
        
        int pick = numsg[idx] * freq[numsg[idx]];
        if(idx < (int)numsg.size() - 1 && numsg[idx + 1] != numsg[idx] + 1)
            pick += deleteEarn(idx  + 1);
        else
            pick += deleteEarn(idx + 2);
        
        int leave = deleteEarn(idx + 1);

        return ret = max(pick, leave);
    }
};