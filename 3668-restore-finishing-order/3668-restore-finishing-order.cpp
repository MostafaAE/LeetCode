class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) 
    {
        unordered_set<int> raceFriends(friends.begin(), friends.end());

        vector<int> result;

        for(int o : order)
        {
            if(raceFriends.count(o))
                result.push_back(o);
        }

        return result;
    }
};