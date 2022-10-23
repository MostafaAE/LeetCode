class Solution {
public:
    /* 
    * Approach:
    * binary search based on summation math equation
    * 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    
    bool possible(int n, long long rows)
    {
        long long summation = rows * (rows+1)/2;
        return summation <= n;
    }
    int arrangeCoins(int n) 
    {
        int start = 0, end = n, answer{};
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            
            if (possible(n, mid))
                start = mid + 1, answer = mid;
            
            else
                end = mid - 1;
        }
        return answer;
    }
};

