class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) 
    {
        int n = points.size();
        double maxArea = 0;

        for(int i = 0 ; i < n - 2 ; ++i)
            for(int j = i + 1 ; j < n - 1 ; ++j)
                for(int k = j + 1 ; k < n ; ++k)
                    maxArea = max(maxArea, calculateArea(points[i], points[j], points[k]));

        return maxArea;
    }

    double calculateArea(vector<int>& p1, vector<int>& p2, vector<int>& p3)
    {
        // Using the Shoelace formula for triangle area
        return 0.5 * abs(p1[0]*(p2[1] - p3[1]) + p2[0]*(p3[1] - p1[1]) + p3[0]*(p1[1] - p2[1]));
    }
};