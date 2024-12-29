class Solution {
public:
    vector<string> validStrings(int n) 
    {
        vector<string> result;
        generateBinaryStrings(n, "", result);
        return result;
    }

    void generateBinaryStrings(int n, string curBinaryString, vector<string>& result)
    {
        if(curBinaryString.size() == n)
        {
            result.push_back(curBinaryString);
            return;
        }

        // pick 1
        generateBinaryStrings(n, curBinaryString + "1", result);
        // pick 0
        if(curBinaryString.empty() || curBinaryString.back() != '0')
            generateBinaryStrings(n, curBinaryString + "0", result);
    }
};