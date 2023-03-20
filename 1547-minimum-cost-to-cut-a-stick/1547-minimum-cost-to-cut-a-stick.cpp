class Solution {
private:
    static const int MAX = 100 + 3; // 2 for two extra values we add
    int memory[MAX][MAX];
    vector<int> cuts;
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     * 
     * Nested range pattern
     *
     * Complexity:
     * Time Complexity : O(N^3)
     * Space Complexity : O(N^2) where N is the max index
     */
    int minCost(int n, vector<int>& _cuts) 
    {
        cuts = _cuts;  
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        memset(memory, -1, sizeof(memory));
        
        return cutCost(0, (int)cuts.size()-1);
    }
    
    // Find the best cut in this sorted range, exclusively
    int cutCost(int startIdx, int endIdx)
    {
        // 2 Consecutive points. Nothing in between
        // No cuts
        if(endIdx - startIdx == 1)
            return 0;
        
        int &ret = memory[startIdx][endIdx];
        if(ret != -1)
            return ret;
        
        ret = INT_MAX;
        int cost = cuts[endIdx] - cuts[startIdx];
        // For all possible cuts exclusively between range ]start, end[
        for(int split = startIdx+1 ; split < endIdx ; split++)
        {
            int leftCost = cutCost(startIdx, split);
            int rightCost = cutCost(split, endIdx);
            int totalCost = cost + leftCost + rightCost;
            ret = min(ret, totalCost);
        }
        
        return ret;
    }
    
};