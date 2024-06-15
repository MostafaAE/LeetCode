class Solution {
public:
    /*
    * Approach:
    * - Use a map to group the projects by their capital requirements.
    * - Iterate through the projects and use a max-heap (priority queue) to keep track of the most profitable projects that can be afforded given the current capital.
    * - For each iteration (up to k times), add the most profitable project that can be afforded to the current capital and update the capital.
    *
    * Complexity:
    * - Time Complexity: O(nlogn + klogn)
    * - Space Complexity: O(n)
    */
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        int n = capital.size();
        map<int, vector<int>> capToProfits;
        priority_queue<int> maxProfit;
        
        // Group projects by their capital requirement
        for(int i = 0; i < n; ++i)
            capToProfits[capital[i]].push_back(profits[i]);
        
        auto itr = capToProfits.begin();
        while(k--)
        {
            // Add all affordable projects to the max-heap
            while(itr != capToProfits.end() && itr->first <= w)
            {
                auto& v = itr->second;
                for(auto val : v)
                    maxProfit.push(val);
                ++itr;
            }
            
            // If no projects can be selected, break the loop
            if(maxProfit.empty())
                break;
            
            // Select the most profitable project and update the capital
            int profit = maxProfit.top();
            maxProfit.pop();
            w += profit;
        }
        
        return w;
    }
};
