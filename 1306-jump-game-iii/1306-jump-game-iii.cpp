class Solution {
public:
    /* 
    * Approach:
    * Breadth first search
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    bool canReach(vector<int>& arr, int start) 
    {
        if(!arr[start])
            return true;
        
        int n{(int)arr.size()};
        vector<bool> visited(n, 0);
        queue<int> q;
        int ops[] = {-1, 1};
        
        q.push(start);
        visited[start] = true;
        
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            for(int op : ops)
            {
                int neighbour = cur + arr[cur]*op;
                if(neighbour >= 0 && neighbour < n && !visited[neighbour])
                {
                    if(!arr[neighbour])
                        return true;
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        
        return false;
        
    }
};