class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size(), sum{};
        vector<int> sumKStartingFromIdx(n, INT_MIN);

        for(int i = n-1 ; i >= 0 ; --i)
        {
            sum += nums[i];

            if(n-i >= k)
            {
                sumKStartingFromIdx[i] = sum;
                sum -= nums[i+k-1];
            }
        }
        
        vector<vector<pair<int, vector<int>>>> maxSumToStartingIndecies(n, vector<pair<int, vector<int>>>(4, {INT_MIN, vector<int>()}));
        auto result = dp(0, 3, k, sumKStartingFromIdx, maxSumToStartingIndecies).second;
        reverse(result.begin(), result.end());
        return result;
    }

    pair<int, vector<int>> dp(int idx, int remainingSubarrays, int k, vector<int>& sumKStartingFromIdx, vector<vector<pair<int, vector<int>>>>& maxSumToStartingIndecies)
    {
        if(idx >= sumKStartingFromIdx.size() ||
            remainingSubarrays == 0 ||
            (sumKStartingFromIdx[idx] == INT_MIN && remainingSubarrays > 0))
            return {0, vector<int>()};
        
        if(maxSumToStartingIndecies[idx][remainingSubarrays].first != INT_MIN)
            return maxSumToStartingIndecies[idx][remainingSubarrays];

        // pick this index
        auto pick = dp(idx + k, remainingSubarrays - 1, k, sumKStartingFromIdx, maxSumToStartingIndecies);
        pick.first += sumKStartingFromIdx[idx];
        pick.second.push_back(idx);
        // leave this index
        auto leave = dp(idx + 1, remainingSubarrays, k, sumKStartingFromIdx, maxSumToStartingIndecies);

        if(pick.first >= leave.first)
            return maxSumToStartingIndecies[idx][remainingSubarrays] = pick;

        return maxSumToStartingIndecies[idx][remainingSubarrays] = leave;
    }
};