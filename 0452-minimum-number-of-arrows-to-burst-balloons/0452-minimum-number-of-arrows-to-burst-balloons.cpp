class Solution {
public:
    /* 
    * Approach:
    * Sort points, and for each point we have two cases (greedy)
    * case 1: no overlap with last arrow, then throw a new arrow at the end of this point
    * case 2: overlap with last arrow, then adjust the point of last arrow to be the minimum of this point and last point ends
    * 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(1)
    */
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        int lastArrow{}, n{(int)points.size()}, count{1};
        sort(points.begin(), points.end());
        
        lastArrow = points[0][1];
        
        for(int i = 1 ; i < n ; i++)
        {
            if(lastArrow < points[i][0])
                lastArrow = points[i][1], count++;
            else
                lastArrow = min(lastArrow, points[i][1]);
        }
        
        return count;
    }
};