class Solution {
public:
    /* 
    * Approach:
    * Binary search 
    * Assume countLessEqual(value, m , n) returns how many numbers < value in m*n table
    * Clearly, the bigger the value, the bigger the return => monotonic
    *
    * With this function, we can trivially search for the kth number
    * if total numbers (mid) < k, then we don't have kth number
    * 
    * Complexity:
    * Time Complexity : O(mlog(m*n))
    * Space Complexity : O(1)
    */
    int findKthNumber(int m, int n, int k) 
    {
        int start{1}, end{m*n}, kth{};
        
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
               
            if (countLessEqual(mid, m, n) >= k)
                end = mid - 1, kth= mid;
            else
                start = mid + 1;
        }
    
        return kth;
    }
    
    //O(m)
    int countLessEqual (int val, int m, int n)
    {
        int k{0};
        for(int i = 1 ; i <= m ; i++)
            k += min(val/i, n);
        
        return k;
    }
};