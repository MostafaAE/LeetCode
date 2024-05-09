class Solution {
public:
    /*
    * Approach:
    * - Sort the happiness array in non-ascending order to maximize the overall happiness sum.
    * - Iterate through the first k largest elements of the sorted array (greedy).
    * - For each element, add (happiness[i] - i) or 0 if it's negative.
    *
    * Complexity:
    * - Time Complexity: O(n logn)
    * - Space Complexity: O(1)
    */
    long long maximumHappinessSum(vector<int>& happiness, int k) 
    {
        long long result{};
        sort(happiness.begin(), happiness.end(), greater<int>());
        
        for(int i = 0 ; i < k ; ++i)
            result += max(0, happiness[i] - i);
        
        return result;
    }
};