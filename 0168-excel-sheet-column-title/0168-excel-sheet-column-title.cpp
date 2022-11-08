class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    string convertToTitle(int columnNumber) 
    {
        string result{};
        
        while(columnNumber > 0)
        {
            int shift = (columnNumber%26 + 25) % 26;
            char c = shift + 'A';
            columnNumber = (columnNumber - shift)/26;
            result = c + result;
        }
        
        return result;
    }
};