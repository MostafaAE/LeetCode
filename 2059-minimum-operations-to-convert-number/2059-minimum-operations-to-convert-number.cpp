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
                    if(process(q, visited, cur + nums[i], goal) || 
                       process(q, visited, cur - nums[i], goal) || 
                       process(q, visited, cur ^ nums[i], goal))
                        return level + 1;
                }
            }
            
            level++;
        }
        
        return -1;
        
    }
    
    bool process(queue<int> &q, vector<bool> &visited, int num, int goal)
    {
        if(num == goal)
            return true;
        if(0 <= num && num <= 1000 && !visited[num])
            visited[num] = true, q.push(num);
        return false;
    }
};