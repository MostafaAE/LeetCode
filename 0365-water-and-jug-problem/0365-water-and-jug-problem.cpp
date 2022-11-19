typedef unordered_map<int, unordered_set<int>> HASHSET;
class Solution {
public:
    bool canMeasureWater(int cap1, int cap2, int targetCapacity) 
    {
        if(cap1 + cap2 == targetCapacity || cap1 == targetCapacity || cap2 == targetCapacity)
            return true;
        
        else if (cap1 + cap2 < targetCapacity)
            return false;
        
        queue<pair<int, int>> q;
        HASHSET visited;
        q.push({0, 0});
        visited[0].insert(0);
        
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                auto [j1, j2] = q.front();
                q.pop();
                
                int m1 = min(j1, cap2 - j2), m2 = min(j2, cap1 - j1);
                if(process(q, visited, 0, j2, targetCapacity) || process(q, visited, j1, 0, targetCapacity) 
                   || process(q, visited, cap1, j2, targetCapacity) || process(q, visited, j1, cap2, targetCapacity)
                   || process(q, visited, j1 - m1, j2 + m1, targetCapacity)
                   || process(q, visited, j1 + m2, j2 - m2, targetCapacity))
                    return true;
            }
        }
        
        return false;
    }
    
    bool process(queue<pair<int,int>> &q, HASHSET& visited, int j1, int j2, int targetCapacity)
    {
        if(j1 + j2 == targetCapacity || j1 == targetCapacity || j2 == targetCapacity)
            return true;
        
        // optimization
        if(j1 > j2)
            swap(j1, j2);
        
        if(visited[j1].insert(j2).second)
            q.push({j1, j2});
        
        return false;
    }
};