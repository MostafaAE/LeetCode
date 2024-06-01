class Solution {
public:
    /* 
    * Approach: 
    * - Linear Iteration
    *
    * Complexity:
    * - Time Complexity : O(n)
    * - Space Complexity : O(1)
    */
    int scoreOfString(string s) 
    {
        int score{};
        
        for(int i = 1 ; i < s.size() ; ++i)
            score += abs(s[i] - s[i-1]);
        
        return score;
    }
};