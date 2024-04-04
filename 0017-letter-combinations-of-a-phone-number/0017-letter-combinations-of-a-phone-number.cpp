class Solution {
private:
    vector<string> letters{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    /* 
    * Approach:
    * Backtracking approach
    * 
    * Complexity:
    * Time Complexity : O(n.4^n) => where n is the length of the digits
    * Space Complexity : O(n) => auxiliary space for recursion
    */
    vector<string> letterCombinations(string digits) 
    {
        if(digits.empty())
            return {};
        
        vector<string> result;
        letterComb(0, digits, result, "");
        return result;
    }
    
    void letterComb(int idx, string& digits, vector<string>& result, string curLetters)
    {
        if(idx >= digits.size())
        {
            result.push_back(curLetters);
            return;
        }
        
        int lettersIdx = digits[idx] - '2';
        for(char c : letters[lettersIdx])
            letterComb(idx + 1, digits, result, curLetters + c);
    }
};