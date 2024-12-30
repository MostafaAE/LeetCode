class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) 
    {
        int queriesCount = queries.size(), pointsCount = points.size();
        vector<int> result(queriesCount, 0);
        for(int i = 0 ; i < queriesCount ; ++i)
        {
            int count{};
            for(int j = 0 ; j < pointsCount ; ++j)
                count += isPointInCircle(points[j], queries[i]);
            result[i] = count;
        }   

        return result;
    }

    bool isPointInCircle(vector<int>& point, vector<int>& query)
    {
        double euclideanDistance = sqrt(pow(point[0]-query[0], 2) + pow(point[1]-query[1], 2));
        return euclideanDistance <= query[2];
    }
};