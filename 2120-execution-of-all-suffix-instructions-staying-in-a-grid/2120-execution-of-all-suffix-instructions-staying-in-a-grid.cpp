class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) 
    {
        unordered_map<char, pair<int, int>> charToMovement {
            {'R', {0, 1}}, {'L', {0, -1}},
            {'U', {-1, 0}}, {'D', {1, 0}}
        };

        int len = s.size();
        vector<int> result(len, 0);
        for(int i = 0 ; i < len ; ++i)
        {
            int curX = startPos[0], curY = startPos[1], count{};
            for(int j = i ; j < len ; ++j)
            {
                auto&[x, y] = charToMovement[s[j]];
                curX += x, curY += y;

                if(!isValid(curX, curY, n))
                    break;

                ++count;
            }
            result[i] = count;
        }

        return result;
    }

    bool isValid(int row, int col, int n)
    {
        if(0 > row || row >= n || 0 > col || col >= n)
            return false;
        return true;
    }
};