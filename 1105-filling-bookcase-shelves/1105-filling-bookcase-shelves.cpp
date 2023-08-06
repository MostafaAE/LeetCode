const int MAX = 1000 + 1;
int memory[MAX];

class Solution {
public:
    /*
     * Approach:
     * Dynamic Programming Tabulation
     * 
     * Direct Consecutive range pattern
     * We want to find a good blocks split
     *
     * Complexity:
     * Time Complexity : O(N^2)
     * Space Complexity : O(N) where N is the max index
     */
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) 
    {   
        for(int i = 0 ; i < (int)books.size() ; i++)
        {
            memory[i] = INT_MAX;
            int booksHeight{}, booksThickness{};
            for(int split = i ; split >= 0 ; split--)
            {
                booksThickness += books[split][0];

                if(booksThickness > shelfWidth)
                    break;

                booksHeight = max(booksHeight, books[split][1]);

                memory[i] = min(memory[i], booksHeight + answer(split - 1));
            }
        }
            
       return memory[(int)books.size() - 1];
    }
    
    int answer(int index)
    {
        if(index <= -1)
            return 0;
        
        return memory[index];
    }
};