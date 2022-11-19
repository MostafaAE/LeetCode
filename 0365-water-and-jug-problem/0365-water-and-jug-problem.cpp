typedef unordered_map<int, unordered_set<int>> HASHSET;
class Solution {
public:
    bool canMeasureWater(int jug1, int jug2, int targetCapacity) 
    {
        if(jug1 + jug2 == targetCapacity || jug1 == targetCapacity || jug2 == targetCapacity)
            return true;
        
        else if (jug1 + jug2 < targetCapacity)
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
                
                int m1 = min(j1, jug2 - j2), m2 = min(j2, jug1 - j1);
                if(process(q, visited, 0, j2, targetCapacity) || process(q, visited, j1, 0, targetCapacity) 
                   || process(q, visited, jug1, j2, targetCapacity) || process(q, visited, j1, jug2, targetCapacity)
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
        
        if(visited[j1].insert(j2).second)
            q.push({j1, j2});
        return false;
    }
};