class Solution {
public:
    /*
     * Approach:
     * Binary search the pivot integer.
     *
     * Complexity:
     * Time Complexity : O(logn)
     * Space Complexity : O(1)
     */
    int pivotInteger(int n) 
    {
        int sumToN = n * (n+1) / 2;
        int start{1}, end{n};
        
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            
            int sumToVal = mid * (mid + 1) / 2;
            int sumValToN = sumToN - sumToVal + mid;
            
            if(sumValToN == sumToVal)
                return mid;
            else if(sumToVal < sumValToN)
                start = mid + 1;
            else
                end = mid - 1;
        }
        
        return -1;
    }
};