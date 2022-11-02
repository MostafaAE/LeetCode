class Solution {
public:
    /* 
    * Approach:
    * use binary search to find the first civilian in a each row to get civilians count
    * and use a priority queue to sort each row's civilians count along thier indecies
    * 
    * Complexity:
    * Time Complexity : O(mlog(m+n))
    * Space Complexity : O(n)
    */
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector<int> result;
        priority_queue<pair<int,int>> pq;
        
        int m = mat.size(), n = mat[0].size();
        
        for(int i = 0 ; i < m ; i++)
        {
            // O(logn)
            auto ub = upper_bound(mat[i].rbegin(), mat[i].rend(), 0);
            int civilians = ub-mat[i].rbegin();
            
            // O(logm)
            pq.push({civilians, -i});
        }
        
        //O(klogm)
        for(int i = 0 ; i < k ; i++)
            result.push_back(-pq.top().second), pq.pop();
        
        return result;
    }
};