class Solution {
public:
    /*
    * Approach:
    * - Use backtracking to generate all possible subsets of the given array.
    * - For each subset, check if it forms a beautiful subset based on the condition:
    * - A subset is beautiful if no two elements in the subset differ by exactly `k`.
    * - Count the number of beautiful subsets encountered during the backtracking process.
    *
    * Complexity:
    * - Time Complexity: O(2^n), where n is the number of elements in the array.
    *   - There are 2^n possible subsets.
    * - Space Complexity: O(n)
    */
    int beautifulSubsets(vector<int>& nums, int k) 
    {
        int count{};
        unordered_map<int, int> visited;
        
        generateBeautifulSubsets(0, k, nums, visited, count);
        
        return count;
    }
    
    void generateBeautifulSubsets(int idx, int k, vector<int>& nums, unordered_map<int, int>& visited, int& count, int subsetSize = 0)
    {
        if(idx >= nums.size())
        {
            count = count + (subsetSize > 0);
            return;
        }
        
        // we have 2 choices
        
        // 1. pick the current number
        if(!visited[nums[idx]-k] && !visited[nums[idx]+k])
        {
            visited[nums[idx]]++;
            generateBeautifulSubsets(idx + 1, k, nums, visited, count, subsetSize + 1);
            visited[nums[idx]]--;
        }
        
        // 2. leave the current number
        generateBeautifulSubsets(idx + 1, k, nums, visited, count, subsetSize);
    }
};