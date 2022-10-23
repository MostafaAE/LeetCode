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
    int arrangeCoins(int n) 
    {
        int start = 0, end = n;
        
        while(start <= end)
        {
            long long k = start + (end-start)/2;
            
            long long summation = k*(k+1) / 2;
            
            if(summation == n)
                return k;
            
            else if (summation > n)
                end = k-1;
            
            else
                start = k+1;
            
        }
        return end;
    }
};

