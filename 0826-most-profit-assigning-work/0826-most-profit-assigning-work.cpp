class Solution {
public:
    /*
    * Approach:
    * - Pair each job's difficulty with its profit and sort the jobs by difficulty.
    * - Sort the workers by their ability.
    * - Iterate over each worker, and for each worker, find the maximum profit they can achieve based on their ability.
    * - Use a two-pointer technique to keep track of the most profitable job that each worker can do.
    * 
    * Complexity:
    * - Time Complexity: O(n log n + m log m)
    *   - Sorting the jobs takes O(n log n).
    *   - Sorting the workers takes O(m log m).
    *   - The iteration over the workers and jobs together takes O(m + n).
    * - Space Complexity: O(n)
    *   - The extra space used is for storing the job pairs.
    */
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
    {
        int totalProfit{};
        vector<pair<int, int>> jobs;
        
        // Pair each job's difficulty with its profit
        for(int i = 0 ; i < (int)profit.size() ; i++)
            jobs.push_back({difficulty[i], profit[i]});
        
        // Sort jobs by difficulty
        sort(jobs.begin(), jobs.end());
        
        // Sort workers by their ability
        sort(worker.begin(), worker.end());
        
        int job{}, maxProfitSoFar{};
        // Iterate over each worker
        for(int i = 0 ; i < (int)worker.size() ; i++)
        {
            // Find the most profitable job the worker can do
            while(job < jobs.size() && worker[i] >= jobs[job].first)
            {
                maxProfitSoFar = max(maxProfitSoFar, jobs[job].second);
                job++;
            }
            
            // Add the maximum profit the worker can achieve to the total profit
            totalProfit += maxProfitSoFar;
        }
        
        return totalProfit;
    }
};
