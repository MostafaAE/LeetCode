class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) 
    {
        unordered_map<string, int> ruleMap = {{"type", 0}, {"color", 1}, {"name", 2}};
        int ruleId = ruleMap[ruleKey];
        
        int count = 0;
        for (const auto& item : items)
            count += item[ruleId] == ruleValue;

        return count;
    }
};