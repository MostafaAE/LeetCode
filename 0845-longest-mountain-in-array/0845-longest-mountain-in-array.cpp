class Solution {
public:
    /* 
    * Approach:
    * Calculate the number of increasing values up to each element and decreasing values after each element, then get the longest mountain array.
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    int longestMountain(vector<int>& arr) 
    {
        int n{(int)arr.size()};
        
        if(n < 3)
            return 0;
        
        int longest{};
        vector<int> increasingTo(n, 0);
        vector<int> decreasingTo(n, 0);
        
        for(int left = 1, right = n-2 ; left < n ; left++, right--)
        {
            if(arr[left] > arr[left - 1])
                increasingTo[left] = increasingTo[left-1] + 1;
            if(arr[right] > arr[right + 1])
                decreasingTo[right] = decreasingTo[right+1] + 1;
        }
        
        for(int i = 1 ; i < n - 1 ; i++)
        {
            if(increasingTo[i] && decreasingTo[i])
                longest = max(longest, increasingTo[i]+decreasingTo[i]+1);
        }
        
        return longest; 
    }
};