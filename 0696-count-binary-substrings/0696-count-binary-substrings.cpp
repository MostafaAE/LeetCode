class Solution {
public:
    /* 
    * Approach:
    * Traverse the string character by character and count the number of consecutive characters.
    * Whenever a character changes, update the last consecutive count and reset the consecutive count.
    * Increment the count of binary substrings whenever the consecutive count is less than or equal to the last consecutive count.
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int countBinarySubstrings(string s) 
    {
        int count{}, lastConsecutiveCount{}, consecutiveCount{1};
        
        for(int i = 1 ; i < (int)s.size() ; i++)
        {
            // flip
            if(s[i] != s[i - 1])
            {
                lastConsecutiveCount = consecutiveCount;
                consecutiveCount = 1;
                count++;
            }
            else
            {
                consecutiveCount++;
                if(consecutiveCount <= lastConsecutiveCount)
                    count++;
            }
        }
        
        return count;
    }
};