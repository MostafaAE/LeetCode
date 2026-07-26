class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
    {
        int n = difficulty.size(), m = worker.size();
        vector<pair<int, int>> profitToDifficulty;

        for(int i = 0 ; i <  n ; ++i)
        {
            profitToDifficulty.push_back({profit[i], difficulty[i]});
        }

        sort(worker.begin(), worker.end(), greater<>());
        sort(profitToDifficulty.begin(), profitToDifficulty.end(), greater<>());

        int maxProfit = 0;
        for(int i = 0, j = 0; i < m && j < n; ++i)
        {
            while(worker[i] < profitToDifficulty[j].second)
                ++j;
            
            if(j < n && worker[i] >= profitToDifficulty[j].second)
                maxProfit += profitToDifficulty[j].first;
        }

        return maxProfit;
    }
};