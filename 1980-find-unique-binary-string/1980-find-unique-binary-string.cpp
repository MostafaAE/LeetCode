class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) 
    {
        unordered_set<string> uniqueStrings(nums.begin(), nums.end());

        int n = nums[0].size();

        return generateBinaryString(n, uniqueStrings, "");
    }

    string generateBinaryString(int n, unordered_set<string>& uniqueStrings, string currentString)
    {
        if(currentString.size() == n)
        {
            if(uniqueStrings.insert(currentString).second)
                return currentString;

            return "";
        }

        string withZero = generateBinaryString(n, uniqueStrings, currentString + "0");
        if(!withZero.empty())
            return withZero;
        
        return generateBinaryString(n, uniqueStrings, currentString + "1");
    }
};