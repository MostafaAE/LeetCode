class Solution {
public:
    string getHappyString(int n, int k) 
    {
        int curIdx{};
        string happyKString{}, currentString{};

        backtrack(n, k, curIdx, currentString, happyKString);

        return happyKString;
    }

    void backtrack(int n, int k, int& curIdx, string& currentString, string& result)
    {
        if(currentString.size() == n)
        {
            ++curIdx;

            if(curIdx == k)
                result = currentString;

            return;
        }
        
        for(char c = 'a' ; c <= 'c' ; ++c)
        {
            if(currentString.empty() || currentString.back() != c)
            {
                currentString += c;
                backtrack(n, k, curIdx, currentString, result);
                currentString.pop_back();
            }
        }
    }
};