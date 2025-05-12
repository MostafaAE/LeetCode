const int MAX = 1000 + 1;
int memory[MAX], shelfWidth;
vector<vector<int>> books;

class Solution {
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     * 
     * Direct Consecutive range pattern
     * We want to find a good blocks split
     *
     * dp(idx)
     *  Try all consecutive ranges as long as total width <= shelfWidth
     *      For each choice [idx, k] subarray, recurse on the remaining dp(k+1)
     *		The choice cost is the max height in the subarray [idx, k]
     *
     * Complexity:
     * Time Complexity : O(N^2)
     * Space Complexity : O(N) where N is the max index
     */
    int minHeightShelves(vector<vector<int>>& books_, int shelfWidth_) 
    {
        books = books_;
        shelfWidth = shelfWidth_;
        memset(memory, -1, sizeof(memory));
        
        return bestSplit(0);
    }
    
    int bestSplit(int index)
    {
        if(index >= (int)books.size())
            return 0;
        
        int &ret = memory[index];
        if(ret != -1)
            return ret;
        
        ret = INT_MAX;
        int booksHeight{}, booksThickness{};
        for(int split = index ; split < (int)books.size() ; split++)
        {
            booksThickness += books[split][0];
            
            if(booksThickness > shelfWidth)
                break;
            
            booksHeight = max(booksHeight, books[split][1]);
            
            ret = min(ret, booksHeight + bestSplit(split+1));
        }
        
        return ret;
    }
};