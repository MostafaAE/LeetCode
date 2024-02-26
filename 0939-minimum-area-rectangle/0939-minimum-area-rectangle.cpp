class Solution {
public:
    /* 
    * Approach:
    * Utilize a hashmap that map each X value to a hashset of different Y values, Iterate on each two points calculating the area if all four points of (x1,y1), (x1, y2), (x2, y1), (x2, y2) exists.
    * 
    * Complexity:
    * Time Complexity : O(n^2)
    * Space Complexity : O(n)
    */
    int minAreaRect(vector<vector<int>>& points) 
    {        
        unordered_map<int, unordered_set<int>> xToYs;
        int minArea{INT_MAX}, n{(int)points.size()};
        
        for(auto &p : points)
            xToYs[p[0]].insert(p[1]);
        
        for(int i = 0 ; i < n ; i++)
        {
            int x1 = points[i][0], y1 = points[i][1];
            
            for(int j = i + 1 ; j < n ; j++)
            {
                int x2 = points[j][0], y2 = points[j][1];
            
                if(x1 == x2 || y1 == y2)
                    continue;
                // we have (x1, y1) and (x2, y2)
                // check if (x1, y2) and (x2, y1) exist
                // so we can calculate the area of the rectangle consisting of the four points
                if(!xToYs[x1].count(y2) || !xToYs[x2].count(y1))
                    continue;
                
                int area = abs(x2-x1) * abs(y2-y1);
                minArea = min(minArea, area);
            }
        }
        
        if(minArea == INT_MAX)
            minArea = 0;
        
        return minArea;
    }
};