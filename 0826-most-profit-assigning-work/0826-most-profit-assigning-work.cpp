class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(nlogn + mlogm)
    * Space Complexity : O(n)
    */
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
    {
        int totalProfit{};
        vector<pair<int, int>> jobs;
        
        //O(n)
        for(int i = 0 ; i < (int)profit.size() ; i++)
            jobs.push_back({difficulty[i], profit[i]});
        
        // O(nlogn)
        sort(jobs.begin(), jobs.end());
        
        // O(mlogm)
        sort(worker.begin(), worker.end());
        
        // O(m+n)
        int job{}, maxProfitSoFar{};
        for(int i = 0 ; i < (int)worker.size() ;i++)
        {
            while(job < jobs.size() && worker[i] >= jobs[job].first)
            {
                maxProfitSoFar = max(maxProfitSoFar, jobs[job].second);
                job++;
            }
            
            totalProfit += maxProfitSoFar; // best profit for the ith worker
        }
        
        return totalProfit;
        
    }
};