class Solution {
public:
    /*
    * Approach:
    * - Use a backtracking approach to find all possible palindrome partitions of the given string.
    * - At each position in the string, try to partition it by checking all possible substrings starting from that position.
    * - If a substring is a palindrome, add it to the current partition and recursively partition the rest of the string.
    * - When the end of the string is reached, add the current partition to the result.
    *
    * Complexity:
    * - Time Complexity: O(n * 2^n), where n is the length of the string.
    *   - There are 2^n possible partitions.
    *   - Checking if a substring is a palindrome takes O(n) time.
    * - Space Complexity: O(n), for the recursive stack space.
    */
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> result;
        vector<string> curPartition;
        
        dfs(0, s, curPartition, result);
        
        return result;
    }
    
    void dfs(int idx, string& s, vector<string>& curPartition, vector<vector<string>>& result)
    {
        if(idx >= s.size())
        {
            result.push_back(curPartition);
            return;
        }
        
        for(int j = idx ; j < s.size() ; ++j)
        {
            if(isPalindrome(s, idx, j))
            {
                curPartition.push_back(s.substr(idx, j-idx+1));
                dfs(j+1, s, curPartition, result);
                curPartition.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] != s[end])
                return false;
            ++start;
            --end;
        }
        
        return true;
    }
};