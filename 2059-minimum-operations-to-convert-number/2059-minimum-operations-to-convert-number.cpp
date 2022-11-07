class Solution {
public:
    /* 
    * Approach:
    * breadth first search
    * 
    * Complexity:
    * Total number of states = O(M) = 1001
    * Time Complexity : O(N*M) where N is the array size
    * Space Complexity : O(M)
    */
    int minimumOperations(vector<int>& nums, int start, int goal) 
    {
        vector<bool> visited(1001,0);
        queue<int> q;
        
        q.push(start);
        visited[start] = 1;
        int level = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                int cur = q.front();
                q.pop();

                for(int i = 0 ; i < (int)nums.size() ; i++)
                {
                    int ops[3] = {cur+nums[i], cur-nums[i], cur^nums[i]};
                    
                    for(int j = 0 ; j < 3 ; j++)
                    {
                        if(ops[j] == goal)
                            return level+1;
                        
                        if(0 <= ops[j] && ops[j] <= 1000 && !visited[ops[j]])
                            q.push(ops[j]), visited[ops[j]] = 1;
                    }
                }
            }
            
            level++;
        }
        
        return -1;
    }
};