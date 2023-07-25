const int MAX = 1000 + 1;
int memory[MAX][MAX];
string str;
class Solution {
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     *
     * Complexity:
     * Time Complexity : O(n^2)
     * Space Complexity : O(n^2)
     */
    string longestPalindrome(string s) 
    {
        str = s;
        memset(memory, -1, sizeof(memory));
        int longestPalindromeStart{}, longestPalindromeLength{};
        
        // Try all ranges and pick the longest
		// Think in any recursive call as O(1)
		// So this 2 nested are O(n^2)
        for(int start = 0 ; start < (int)str.size() ; start++)
            for(int end = start ; end < (int)str.size() ; end++)
                if(isPalindrome(start, end) && end-start+1 > longestPalindromeLength)
                    longestPalindromeLength = end - start + 1, longestPalindromeStart = start;
        
        return str.substr(longestPalindromeStart, longestPalindromeLength);        
    }
    
    bool isPalindrome(int startIdx, int endIdx)
    {
        // range is done
        if(startIdx >= endIdx)
            return 1;
        
        int &ret = memory[startIdx][endIdx];
        if(ret != -1)
            return ret;
        
        if(str[startIdx] != str[endIdx])
            return ret = 0;
        
        return ret = isPalindrome(startIdx + 1, endIdx - 1);
    }
};