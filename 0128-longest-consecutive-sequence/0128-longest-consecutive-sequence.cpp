class Solution {
public:
    /* 
    * Approach:
    * reduce the problem to a graph and perfrom depth first search to get each chain
    * the answer is the size of the longest chain
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLength{};
        
        // get the length of each chain
        for(int elem : s)
            if(!s.count(elem-1))
                maxLength = max(maxLength, dfs(s, elem));
        
        return maxLength;
    }
    
    int dfs(unordered_set<int>& s, int node)
    {
        int length{1};
        
        while(s.count(node+1))
            node++, length++;
        
        return length;
    }
};