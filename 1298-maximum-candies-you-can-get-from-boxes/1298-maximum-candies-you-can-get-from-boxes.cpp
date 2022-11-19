class Solution {
public:
    /* 
    * Approach:
    * Simulation using Breadth first search
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& availableBoxes) 
    {
        int totalCandies{};
        queue<int> q;
        
        processBoxes(q, availableBoxes, status);
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int cur = q.front();
                q.pop();
                
                totalCandies += candies[cur];
                
                for(int key : keys[cur])
                    status[key] = 1;
                
                for(int b : containedBoxes[cur])
                    availableBoxes.push_back(b);
            }
            
            processBoxes(q, availableBoxes, status);
        }
    
        return totalCandies;
    }
    
    void processBoxes(queue<int>& q, vector<int>& availableBoxes, vector<int>& status)
    {
        for(int i = 0 ; i < (int)availableBoxes.size() ; i++)
        {
            int box = availableBoxes[i];
            if(status[box])
            {
                q.push(box);
                swap(availableBoxes[i], availableBoxes.back());
                availableBoxes.pop_back();
            }
        }
    }
};

                