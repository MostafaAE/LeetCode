class Solution {
public:
    /* 
    * Approach:
    * Breadth first search
    * 
    * Complexity:
    * Total number of states = O(D) = 4
    * Time Complexity : O(D * 10^D) << constant 
    * Space Complexity : O(10^D) << constant 
    */
    int openLock(vector<string>& deadends, string target) 
    {
        string start = "0000";
        unordered_set<string> visited(deadends.begin(), deadends.end());
        queue<string> q;
        const int D = 4; // number of digits
        
        if(visited.count(start))
            return -1;
        if(target == start)
            return 0;
        
        q.push(start);
        visited.insert(start);
        int level{};
        
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                string cur = q.front();
                q.pop();

                for(int i = 0 ; i < D ; i++)
                {
                    string next = cur, prev = cur;
                    next[i] += 1;
                    prev[i] -= 1;
                    // wrap around
                    if(next[i] > '9')
                        next[i] = '0';
                    
                    if(prev[i] < '0')
                        prev[i] = '9';
                    
                    if(process(q, visited, next, target) || process(q, visited, prev, target))
                        return level + 1;
                }
            }
            level++;
        }
        return -1;
    }
    
    bool process(queue<string>& q, unordered_set<string>& visited, string str, string target)
    {
        if(str == target)
            return true;
                    
        if(visited.insert(str).second)
            q.push(str);
        
        return false;
    }
};