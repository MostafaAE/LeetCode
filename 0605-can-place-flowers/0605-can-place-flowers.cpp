class Solution {
public:
    /*
     * Approach:
     * - Iterate through the flowerbed, if the current position is empty, check if the previous and next positions are also empty.
     * - If both the previous and next positions are empty, plant a flower at the current position and move two steps forward.
     * - Return true if the count of planted flowers is equal to the required number of flowers (n).
     *
     * Complexity:
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int count = 0;
        for(int i = 0 ; count < n && i < flowerbed.size() ; i++)
        {
            if(flowerbed[i] == 0)
            {
                bool isEmptyBefore = (i == 0 || flowerbed[i - 1] == 0);
                bool isEmptyAfter = (i == flowerbed.size()-1 || flowerbed[i + 1] == 0);
                
                if(isEmptyBefore && isEmptyAfter)
                    ++count, ++i;
            }
        }
        return count == n;
    }
};