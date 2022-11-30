class Solution {
public:
    /* 
    * Approach:
    * Simulation
    * 
    * Complexity:
    * Time Complexity : O(m*n)
    * Space Complexity : O(1) => neglecting the output space
    */
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int left{}, right{(int)matrix[0].size()-1}, top{}, bottom{(int)matrix.size()-1};
        vector<int> result;
        
        while(left <= right && top <= bottom)
        {
            for(int i = left ; i <= right && top <= bottom ; i++)
                result.push_back(matrix[top][i]);
             top++;
            
            for(int i = top ; i <= bottom && left <= right ; i++)
                result.push_back(matrix[i][right]);
            right--;
            
            for(int i = right ; i >= left && top <= bottom ; i--)
                result.push_back(matrix[bottom][i]);
            bottom--;
            
            for(int i = bottom ; i >= top && left <= right; i--)
                result.push_back(matrix[i][left]);
            left++;
        }
        
        return result;
    }
};