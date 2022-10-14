class Solution {
public:
    
    /* 
    * Approach:
    * for each row in the triangle, initialize a vector with 1's then
    * iterate starting from the second element to the before last element
    * setting its value to the sum of the two numbers directly above it 
    * row[j] = triangle[i-1][j-1] + triangle[i-1][j];
    * 
    * Complexity:
    * Time Complexity : O(n^2)
    * Space Complexity : O(1) >> neglecting the output space
    */
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> triangle (1, vector<int>(1,1));
        
        for(int i = 1 ; i < numRows ; i++)
        {
            vector<int> row(i+1, 1);
            
            for(int j = 1 ; j < i ; j++)
                row[j] = triangle[i-1][j-1] + triangle[i-1][j];
            
            triangle.push_back(row);
        }
        
        return triangle;
    }
};