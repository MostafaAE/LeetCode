class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        int n = blocks.size();
        int minWhiteCount{INT_MAX}, currentWhiteCount{};

        for(int i = 0 ; i < n ; ++i)
        {
            if(i < k)
            {
                currentWhiteCount += blocks[i] == 'W';
            }
            else
            {
                minWhiteCount = min(minWhiteCount, currentWhiteCount);
                currentWhiteCount += blocks[i] == 'W';
                currentWhiteCount -= blocks[i - k] == 'W';
            }
        }

        minWhiteCount = min(minWhiteCount, currentWhiteCount);

        return minWhiteCount;
    }
};