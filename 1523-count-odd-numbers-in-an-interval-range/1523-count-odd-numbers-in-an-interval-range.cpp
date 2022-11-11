class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(1)
    * Space Complexity : O(1)
    */
    int countOdds(int low, int high) 
    {
        // get numbers count
        int count = high - low + 1;
        
        // count is odd and low or high is odd
        if(count&1 && (low&1 || high&1))
            return count / 2 + 1;
        return count / 2;
    }
    
};