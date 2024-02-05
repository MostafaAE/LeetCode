class Solution {
public:
    /* 
    * Approach:
    * Calculate the number of ups and downs for each element.
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int longestMountain(vector<int>& arr) 
    {
        int n{(int)arr.size()}, longest{};
        
        for(int i = 1, up = 0, down = 0 ; i < n ; i++)
        {
            if(down && arr[i] > arr[i - 1] || arr[i] == arr[i - 1])
                up = down = 0;
            
            up += arr[i] > arr[i - 1];
            down += arr[i] < arr[i - 1];
                
            if(up && down)
                longest = max(longest, up + down + 1);
        }
        return longest; 
    }
};