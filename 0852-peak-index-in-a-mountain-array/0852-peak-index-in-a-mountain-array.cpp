class Solution {
public:
    /* 
    * Approach:
    * binary search
    * 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int start{1}, end{(int)arr.size()-2};
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])
                return mid;
            else if (arr[mid-1] < arr[mid])
                start = mid +1;
            else
                end = mid - 1;
        }
        return 0;
    }
};