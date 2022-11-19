class Solution {
private:
    vector<vector<int>> dir {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
public:
    /* 
    * Approach:
    * Breadth first search
    * 
    * Complexity:
    * Time Complexity : O(n!) >> where n = 6
    * Space Complexity : O(n!)
    */
    int slidingPuzzle(vector<vector<int>>& board) 
    {
        string goal{"123450"};
        string start{};
        
        for(int i = 0 ; i < 2 ; i++)
            for(int j = 0 ; j < 3 ; j++)
                start += board[i][j] + '0';
        
        if(start == goal)
            return 0;
        
        queue<string> q;
        unordered_set<string> visited;
        
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
                
                int idx1 = cur.find('0');
                
                for(int idx2 : dir[idx1])
                {
                    swap(cur[idx1], cur[idx2]);

                    if(cur == goal)
                        return level+1;

                    if(visited.insert(cur).second)
                        q.push(cur);

                    //undo
                    swap(cur[idx1], cur[idx2]);
                }
            }
            level++;
        }
        
        return -1;
    }
};