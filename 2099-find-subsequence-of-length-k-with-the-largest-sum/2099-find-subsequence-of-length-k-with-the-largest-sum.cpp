class Solution {
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> pq;
        set<int> indecies;
        vector<int> result;
        for (int i = 0; i < (int)nums.size(); i++)
        {

            pq.push(make_pair(-nums[i], i));
            if ((int)pq.size() > k)
                pq.pop();
        }

        while (!pq.empty())
            indecies.insert(pq.top().second), pq.pop();

        for (int idx : indecies)
            result.push_back(nums[idx]);
        
        return result;
    }
};