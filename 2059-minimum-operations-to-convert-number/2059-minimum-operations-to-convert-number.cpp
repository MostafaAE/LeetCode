class Solution {
public:
    /* 
    * Approach:
    * Breadth first search
    * 
    * Complexity:
    * Total number of states = O(M) = 1001
    * Time Complexity : O(N*M) where N is the array size
    * Space Complexity : O(M)
    */
    int minimumOperations(vector<int>& nums, int start, int goal) 
    {
        int n{(int)nums.size()};
        
        vector<bool> visited(1001, 0);
        queue<int> q;
        
        visited[start] = true;
        q.push(start);
        int level = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int cur = q.front();
                q.pop();
                
                for(int i = 0 ; i < n ; i++)
                {
                    int results[] = {cur + nums[i], cur - nums[i], cur ^ nums[i]};

                    for(int res : results)
                    {
                        if(res == goal)
                            return level + 1;
                        if(res >= 0 && res <= 1000 && !visited[res])
                            visited[res] = true, q.push(res);
                    }
                }
            }
            
            level++;
        }
        
        return -1;
        
    }
};