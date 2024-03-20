class Solution {
public:
    /* 
    * Approach:
    * Knuth–Morris–Pratt algorithm (KMP).
    * 
    * Complexity:
    * Time Complexity : O(N + M)
    * Space Complexity : O(M)
    */
    int strStr(string haystack, string needle) 
    {
        int n{(int)haystack.size()}, m{(int)needle.size()}, i{}, j{};
        vector<int> LPS = computeLPS(needle);
        
        while(i < n)
        {
            if(haystack[i] == needle[j])
                i++, j++;
            else 
            {
                if(j == 0)
                    i++;
                else
                    j = LPS[j - 1];
            }
            
            if(j == m)
                return i-m;
        }
        
        return -1;
    }
    
    // 
    // longest prefix suffix O(M)
    vector<int> computeLPS(string needle)
    {
        int m{(int)needle.size()};
        vector<int> LPS(m, 0);
        
        int i{1}, prevLPS{};
        
        while(i < m)
        {
            if(needle[i] == needle[prevLPS])
                LPS[i] = prevLPS + 1, prevLPS++, i++;
            else if(prevLPS == 0)
                LPS[i] = 0, i++;
            else
                prevLPS = LPS[prevLPS - 1];
        }
        
        return LPS;
    }
};