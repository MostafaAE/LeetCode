class Solution {
public:
    // Calculates the minimum number of steps required to collect fruits from 'left' to 'right'
    int calculateSteps(const vector<vector<int>>& fruits, int startPos, int left, int right) 
    {
        if (fruits[right][0] <= startPos) 
        {
            return startPos - fruits[left][0];
        } 
        else if (fruits[left][0] >= startPos) 
        {
            return fruits[right][0] - startPos;
        } 
        else 
        {
            return min(abs(startPos - fruits[right][0]), abs(startPos - fruits[left][0])) + fruits[right][0] - fruits[left][0];
        }
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) 
    {
        int n = fruits.size();
        int left = 0, right = 0;
        int currentSum = 0, maxFruits = 0;

        while (right < n) 
        {
            currentSum += fruits[right][1];

            // Shrink window from the left if steps exceed k
            while (left <= right && calculateSteps(fruits, startPos, left, right) > k) 
            {
                currentSum -= fruits[left][1];
                ++left;
            }

            maxFruits = max(maxFruits, currentSum);
            ++right;
        }

        return maxFruits;
    }
};