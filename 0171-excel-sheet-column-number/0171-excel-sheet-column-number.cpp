class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int titleToNumber(string columnTitle) 
    {
        int result{};
        
        for(int i = 0 ; i < columnTitle.size() ; i++)
            result = result * 26 + (columnTitle[i] - 'A' + 1);
        
        return result;
    }
};