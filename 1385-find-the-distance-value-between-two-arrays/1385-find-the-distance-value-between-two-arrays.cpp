class Solution {
public:
    /* 
    * Approach:
    * Sort 'arr2' and use binary search to get the closest element for each 'arr1[i]',
    * and check its distance from the closest if its valid or not
    * 
    * Complexity:
    * Time Complexity : O((m+n)logm)
    * Space Complexity : O(1)
    */
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) 
    {
        int distance{};
        
        // O(mlogm)
        sort(arr2.begin(), arr2.end());
        
        // O(nlogm)
        for(int i = 0 ; i < (int)arr1.size() ; i++)
            if(isValid(arr2, arr1[i], d))
                distance++;
        
        return distance;
    }
    
    bool isValid(vector<int>& arr, int target, int d)
    {
        int start{}, end{(int)arr.size()-1};
        
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            
            if(abs(arr[mid] - target) <= d)
                return false;
            
            if (arr[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return true;
    }
};