const int OO = 1e6;
class Solution {
public:
    /* 
    * Approach:
    * Bellman-Ford shortest path algorithm
    * 
    * Complexity:
    * Time Complexity : O(V.E)
    * Space Complexity : O(V)
    */
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<int> dest(n, OO);
        dest[k-1] = 0;
        
        for(int i = 1 ; i < n ; i++)
        {
            for(auto &e : times)
            {
                int u = e[0] -1, v = e[1]-1 , w = e[2];
                
                if(dest[u] + w < dest[v])
                    dest[v] = dest[u] + w;
            }
        }
        
        int time = *max_element(dest.begin(), dest.end());
        if(time == OO)
            return -1;
        
        return time;
    }
};