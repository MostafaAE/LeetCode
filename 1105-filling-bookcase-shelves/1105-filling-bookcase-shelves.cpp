class Solution {
private:
    static const int MAX = 1000 + 1;
    int memory[MAX], shelfWidth;
    vector<vector<int>> books;
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     *
     * Complexity:
     * Time Complexity : O(N^2)
     * Space Complexity : O(N) where N is the max index
     */
    int minHeightShelves(vector<vector<int>>& _books, int _shelfWidth) 
    {
        books = _books;
        shelfWidth = _shelfWidth;
        memset(memory, -1, sizeof(memory));
        
        return bestSplit(0);
    }
    
    int bestSplit(int idx)
    {
        if(idx >= (int)books.size())
            return 0;
        
        int &ret = memory[idx];
        if(ret != -1)
            return ret;
        
        ret = INT_MAX;
        int widthSum{}, maxHeight{};
        for(int i = idx ; i < (int)books.size() ; i++)
        {
            widthSum += books[i][0];
            if(widthSum > shelfWidth)
                break;
            maxHeight = max(maxHeight, books[i][1]);
            int totalHeight = maxHeight + bestSplit(i+1);
            ret = min(ret, totalHeight);
        }
        
        return ret;
    }
};