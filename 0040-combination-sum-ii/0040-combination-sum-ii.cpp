class Solution {    
public:
    /**
     * Approach:
     * - Sort the candidates to facilitate the skipping of duplicates.
     * - Use backtracking to explore all possible combinations, starting from a given index.
     * - For each candidate, choose it if it doesn't duplicate the previous candidate at the same level.
     * - Recursively reduce the target and continue the search with the next candidates.
     * - If the target reaches zero, add the current combination to the result.
     * - After exploring a candidate, backtrack by removing it from the current combination.
     *
     * Complexity:
     * - Time Complexity: O(2^n) in the worst case, where n is the number of candidates. This is because each candidate can either be included or excluded.
     * - Space Complexity: O(n)
     */
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        int n = candidates.size();
        vector<vector<int>> result;
        vector<int> curCombination;
        
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, result, curCombination, 0, target);
        
        return result;
    }
    
    void backtrack(vector<int>& candidates, vector<vector<int>>& result, vector<int>& curCombination, int idx, int target)
    {
        if(target == 0)
        {
            result.push_back(curCombination);
            return;
        }
        
        for(int i = idx ; i < candidates.size() && target >= candidates[i]; ++i)
        {
            if(i == idx || candidates[i] != candidates[i - 1])
            {
                curCombination.push_back(candidates[i]);
                
                backtrack(candidates, result, curCombination, i + 1, target - candidates[i]);
                
                curCombination.pop_back();
            }
        }
    }
};