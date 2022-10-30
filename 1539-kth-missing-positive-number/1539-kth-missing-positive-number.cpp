class Solution {
public:
    /* 
    * Approach:
    * Binary Search the Kth Missing Positive Number
    * 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    int findKthPositive(vector<int>& arr, int k) 
    {
        int start{}, end{(int)arr.size()-1}, answer{end+1};
        
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            
            if(missing(arr, mid) >= k)
                end = mid - 1 , answer = mid;
            else
                start = mid + 1;
        }
        return kth(arr, answer-1, k);
        
    }
    
    
    // Get the missing numbers count before an index
    int missing(vector<int>& arr, int idx)
    {
        return arr[idx] - idx - 1;
    }
    
    // Get the kth missing number from an index
    int kth(vector<int>& arr, int idx, int k)
    {
        if(idx == -1)
            return k;
        return arr[idx] + k - missing(arr, idx);
    }
    
};