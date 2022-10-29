// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    /* 
    * Approach:
    * binary search the first bad version (monotonic function)
    * 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    int firstBadVersion(int n) 
    {
        int start{1}, end{n} ,answer{};
        
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            
            if(isBadVersion(mid))
                end = mid - 1, answer = mid;
            else
                start = mid + 1;
        }
        
        return answer;
    }
};