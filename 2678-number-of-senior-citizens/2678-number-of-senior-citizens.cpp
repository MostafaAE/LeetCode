class Solution {
public:
    /**
     * Approach:
     * - Iterate through each string in the details vector.
     * - For each string, check the characters at positions 11 and 12 to determine the age.
     *   - If the character at position 11 is '6' and the character at position 12 is '1' or greater, or If the character at position 11 is '7' or greater, increment the count.
     * - Return the total count of seniors.
     *
     * Complexity:
     * - Time Complexity: O(n)
     * - Space Complexity: O(1)
     */
    int countSeniors(vector<string>& details) 
    {
        int count{};
        
        for(string detail : details)
            if(detail[11] >= '6' && detail[12] >= '1' 
               || detail[11] >= '7')
                ++count;
        
        return count;
    }
};
