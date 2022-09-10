class Solution {
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> pq;
        vector<int> result;
        for (int i = 0; i < (int)nums.size(); i++)
        {

            pq.push(make_pair(-nums[i], i));
            if ((int)pq.size() > k)
                pq.pop();
        }

        while (!pq.empty())
            result.push_back(pq.top().second), pq.pop();

        sort(result.begin(), result.end());

        for (int i = 0; i < (int)result.size(); i++)
        {
            result[i] = nums[result[i]];
        }
        return result;
    }
};