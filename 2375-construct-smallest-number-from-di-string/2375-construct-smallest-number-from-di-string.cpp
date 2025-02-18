class Solution {
private:
    string smallestPattern{"99999999999"};
public:
    string smallestNumber(string pattern) 
    {
        unordered_set<int> used;
        for(int i = 1 ; i <= 9 ; ++i)
        {
            used.insert(i);
            backtrack(pattern, used, 0, i, to_string(i));
            used.erase(i);
        }

        return smallestPattern;
    }

    void backtrack(string& pattern, unordered_set<int>& used, int idx, int lastChoice, string curPattern)
    {
        if(idx == pattern.size())
        {
            if(curPattern < smallestPattern)
                smallestPattern = curPattern;

            return;
        }

        int direction = pattern[idx] == 'I' ? 1 : -1;

        for(int val = lastChoice + direction ; 1 <= val && val <= 9 ; val += direction)
        {
            if(!used.count(val))
            {
                used.insert(val);
                backtrack(pattern, used, idx + 1, val, curPattern + to_string(val));
                used.erase(val);
            }
        }
    }
};

