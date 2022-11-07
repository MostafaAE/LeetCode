class Solution {
private:
    int dx[2] = {1, -1};
public:
    /* 
    * Approach:
    * breadth first search
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    bool canReach(vector<int>& arr, int start) 
    {
        if(arr[start] == 0)
            return true;
        
        vector<bool> visited((int)arr.size(), 0);
        queue<int> q;
        
        visited[start] = 1;
        q.push(start);
        
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                int cur = q.front();
                q.pop();
                for(int d = 0 ; d < 2 ; d++)
                {
                    int newIdx = cur + dx[d]*arr[cur];
                    if(newIdx >= 0 && newIdx < arr.size() && !visited[newIdx])
                    {
                        if(arr[newIdx] == 0)
                            return true;
                        visited[newIdx] = 1;
                        q.push(newIdx);
                    }
                }
                
            }
        }
        
        return false;
    }
};