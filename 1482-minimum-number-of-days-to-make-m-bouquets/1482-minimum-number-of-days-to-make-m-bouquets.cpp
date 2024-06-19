class Solution {
public:
    /*
    * Approach:
    * - Use binary search to find the minimum number of days needed to pick m bouquets.
    * - Define the search range from 0 to the maximum value in bloomDay.
    * - For each midpoint in the binary search: Check if it is possible to pick m bouquets in mid days. If possible, update the result and search in the left half; otherwise, search in the right half.
    *
    * Complexity:
    * - Time Complexity: O(n logD), where N is the number of flowers and D is the highest value in the array bloomDay.
    * - Space Complexity: O(1)
    */
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        // If there are not enough flowers to make m bouquets, return -1.
        if(m > (int)bloomDay.size() / k)
            return -1;
        
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int start{}, result = end;
        
        // Perform binary search to find the minimum number of days.
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            
            // Check if it is possible to make m bouquets in mid days.
            if(isPossibleDay(bloomDay, mid, m, k))
            {
                result = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        
        return result;
    }
    
    // Helper function to check if it is possible to make m bouquets in a given number of days.
    bool isPossibleDay(vector<int>& bloomDay, int days, int m, int k)
    {
        int pickedCount{};
        
        for(auto val : bloomDay)
        {
            if(val <= days)
                ++pickedCount;
            else
                pickedCount = 0;
            
            if(pickedCount == k)
            {
                --m;
                pickedCount = 0;
                // Return early if m bouquets are made.
                if(m == 0)
                    return true;
            }
        }
        
        return m <= 0;
    }
};
