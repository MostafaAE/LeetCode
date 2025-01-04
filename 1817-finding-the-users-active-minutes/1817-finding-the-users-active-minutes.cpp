class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) 
    {
        vector<int> result(k, 0);
        unordered_map<int, unordered_set<int>> userToTimes;

        for(auto& log : logs)
        {
            int userId = log[0];
            int time = log[1];
            userToTimes[userId].insert(time);
        }

        for(auto&[userId, times] : userToTimes)
        {
            int uam = times.size();
            if(uam <= k)
                ++result[uam-1];
        }
        
        return result;
    }
};