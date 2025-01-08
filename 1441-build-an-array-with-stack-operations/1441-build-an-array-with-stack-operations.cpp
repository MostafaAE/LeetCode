class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        const string push = "Push", pop = "Pop";
        vector<string> result;
        unordered_set<int> hashSet(target.begin(), target.end());

        int curSize{};
        for(int i = 1 ; i <= n && curSize < target.size() ; ++i)
        {
            ++curSize;
            result.push_back(push);
            if(!hashSet.count(i))
            {
                result.push_back(pop);
                --curSize;
            }
        }

        return result;
    }
};