class Solution {
public:
    /*
     * Approach:
     * Sort the tokens, then use two pointers technique (left, right), always paly the smallest token face up if possible or play the largest token face down while maintaining the highest score (greedy).
     *
     * Complexity:
     * Time Complexity : O(nlogn)
     * Space Complexity : O(1)
     */
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        int n{(int)tokens.size()}, left{}, right{n-1}, maxScore{}, score{};
        
        // O(nlogn)
        sort(tokens.begin(), tokens.end());
        
        // O(n)
        while(left <= right)
        {
            // Play token face-up
            if(power >= tokens[left])
            {
                power -= tokens[left++];
                score++;
                maxScore = max(maxScore, score);
            }
            // Play token face-down
            else if(score > 0)
            {
                power += tokens[right--];
                score--;
            }
            else
                break;
        }
        
        return maxScore;
        
    }
};