using ll = long long;
const int MOD = 1e9 + 7;
class Solution {
public:
    /*
     * Approach:
     * Sort engineers by efficiency, and use a priority queue to keep track of the highest speed engineers.
     *
     * Complexity:
     * Time Complexity : O(nlogn)
     * Space Complexity : O(n)
     */
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        set<pair<int,int>> efficiencyToIdx;
        priority_queue<int, vector<int>, greater<int>> speedHeap;
        ll maxPerformanceVal{}, totalSpeed{};
        
        // O(nlogn)
        for(int i = 0 ; i < n ; i++)
            efficiencyToIdx.insert({efficiency[i], i});
        
        auto itr = efficiencyToIdx.rbegin();
        
        // O(nlogk)
        while(itr != efficiencyToIdx.rend())
        {
            int idx = itr->second;
            ll curEfficiency = itr->first, curSpeed = speed[idx];

            totalSpeed += curSpeed;
            
            speedHeap.push(curSpeed);
            
            if(speedHeap.size() > k)
            {
                totalSpeed -= speedHeap.top();
                // O(logk)
                speedHeap.pop(); 
            }
            
            maxPerformanceVal = max(maxPerformanceVal, totalSpeed * curEfficiency);

            itr++;
        }
        
        return maxPerformanceVal % MOD;
    }
};