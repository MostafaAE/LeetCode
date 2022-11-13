class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) 
    {
        int minDistance{INT_MAX}, smallestIdx{-1};
        
        for(int i = 0 ; i < (int)points.size() ; i++)
        {
            if(points[i][0] == x || points[i][1] == y)
            {
                int manhattanDistance = abs(x-points[i][0]) + abs(y-points[i][1]);
                if(manhattanDistance < minDistance)
                    minDistance = manhattanDistance, smallestIdx = i;
            }
        }
        return smallestIdx;
    }
};