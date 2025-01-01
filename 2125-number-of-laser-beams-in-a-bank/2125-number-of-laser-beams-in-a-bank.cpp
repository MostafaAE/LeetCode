class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int totalCount{}, prevLasersCount{};

        for(const string& row : bank)
        {
            int curLasersCount = countLaserBeams(row);
            if(curLasersCount > 0)
            {
                totalCount += (curLasersCount * prevLasersCount);
                prevLasersCount = curLasersCount;
            }
        }

        return totalCount;
    }

    int countLaserBeams(const string& str)
    {
        int count{};
        for(char c : str)
            count += (c == '1');

        return count;
    }
};