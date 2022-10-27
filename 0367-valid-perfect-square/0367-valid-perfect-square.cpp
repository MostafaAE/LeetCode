class Solution {
public:
    /* 
    * Approach:
    * binary search on monotonic function
    * 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    bool isPerfectSquare(int num) 
    {
        int start{1}, end{num}, answer{};
        
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            
            if(mid <= num / mid)
                start = mid + 1, answer = mid;
            else
                end = mid - 1;
        }
        
        return answer*answer == num;
    }
};