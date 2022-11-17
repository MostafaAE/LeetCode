class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        
        int xDiff = coordinates[1][0] - coordinates[0][0];
        int yDiff = coordinates[1][1] - coordinates[0][1];
        
        // checking if all points have the same slope as the first 2 points
       
        for(int i = 2 ; i < (int)coordinates.size() ; i++)
        {
            int curXDiff = coordinates[i][0] - coordinates[i-1][0];
            int curYDiff = coordinates[i][1] - coordinates[i-1][1];
            
            if(yDiff * curXDiff != xDiff * curYDiff)
                return false;
        }
        
        return true; 
    }
};