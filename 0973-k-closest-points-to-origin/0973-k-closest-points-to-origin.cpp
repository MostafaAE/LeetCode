class Solution {
public:
    /* 
    * Approach:
    * Utilize a priority queue as a max heap and use it to keep track of the k closest points to origin.
    *
    * Complexity:
    * Time Complexity : O(nlogk)
    * Space Complexity : O(k)
    */
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<pair<int, vector<int>>> mxHeap;
        vector<vector<int>> result;
        
        for(auto p : points)
        {
            int dist = distanceSq(p[0], p[1]);
            if(mxHeap.size() >= k && mxHeap.top().first > dist)
                mxHeap.pop();
            
            if(mxHeap.size() < k)
                mxHeap.push({dist, p});
        }
        
        while(!mxHeap.empty())
        {
            result.push_back(mxHeap.top().second);
            mxHeap.pop();
        }
        
        return result;
    }
    
    int distanceSq(int x, int y)
    {
        return x*x + y*y;
    }
};