class Solution {
private:
    const static int MAX = 1000 + 1;
    int memory[MAX][MAX]; // values only -1, 0, 1. We can represent in other ways
    string str;
    
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
        int n{(int)s.size()}, idx{}, length{};

        memset(memory, -1, sizeof(memory));
        str = s;
        
       for(int left = 0 ; left < n ; left++)
       {
           for(int right = n-1 ; right >= left ; right--)
               if(isPalindrome(left, right) && right - left + 1 > length)
                   idx = left, length = right - left + 1;
       }
       
        return s.substr(idx, length);
    }
    
    bool isPalindrome(int left, int right)
    {
        // range is done
        if(left >= right)
            return true;
        
        int &ret = memory[left][right];
        if(ret != -1)
            return ret;
        
        if(str[left] == str[right])
            return ret = isPalindrome(left + 1 , right - 1);
        
        return ret = 0;
        
    }
};