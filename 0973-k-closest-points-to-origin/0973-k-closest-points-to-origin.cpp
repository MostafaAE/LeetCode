class Solution {
public:
    /* 
    * Approach:
    * use a priority queue to store the closest k points and return them
    * 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(n)
    */
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<pair<int,int>> pq;
        vector<vector<int>> result;
        for(int i = 0 ; i < (int)points.size() ; i++)
        {
            int val = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            
            // O(logn)
            pq.push({val, i});
            if(pq.size() > k)
                pq.pop();
        }
            
        for(int i = 0 ; i < k ; i++)
            result.push_back(points[pq.top().second]), pq.pop();
        
        return result;
    }
};