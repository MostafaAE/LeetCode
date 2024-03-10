class Solution {
public:
    /*
     * Approach:
     * Graph Depth-First Search
     *
     * Complexity:
     * Time Complexity : O(V + E)
     * Space Complexity : O(V) where V is the number of nodes, E number of edges
     */
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n{(int)rooms.size()}, roomsCount{};
        
        vector<bool> visited(n, 0);
        
        dfs(rooms, 0, visited, roomsCount);
        
        return roomsCount == n;
    }
    
    void dfs(vector<vector<int>>& rooms, int node, vector<bool>& visited, int& roomsCount)
    {
        visited[node] = true;
        roomsCount++;
        
        for(int neighbour: rooms[node])
            if(!visited[neighbour])
                dfs(rooms, neighbour, visited, roomsCount);
    }
};