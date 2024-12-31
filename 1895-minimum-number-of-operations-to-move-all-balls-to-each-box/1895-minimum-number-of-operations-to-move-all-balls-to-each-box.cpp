class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        int n = boxes.size();
        vector<int> result(n, 0);

        int ballsToLeft{}, movesToLeft{};
        int ballsToRight{}, movesToRight{};

        for(int i = 0, j = n-1 ; i < n ; ++i, --j)
        {
            result[i] += movesToLeft;
            ballsToLeft += boxes[i] - '0';
            movesToLeft += ballsToLeft;

            result[j] += movesToRight;
            ballsToRight += boxes[j] - '0';
            movesToRight += ballsToRight;
        }

        return result;
    }
};