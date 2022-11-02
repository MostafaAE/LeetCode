class Solution {
public:
    /* 
    * Approach:
    * binary search
    *
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(1)
    */
    bool checkIfExist(vector<int>& arr) 
    {
        // O(nlogn)
        sort(arr.begin(), arr.end());
        
        // O(nlogn)
        for(int i = 0 ; i < (int)arr.size() ; i++)
        {
            auto lb = lower_bound(arr.begin(), arr.end(), arr[i]*2);
            int idx = lb-arr.begin();
            if(lb != arr.end() && *lb == arr[i]*2 && idx != i)
                return true;
        }
            
        return false;
    }
};