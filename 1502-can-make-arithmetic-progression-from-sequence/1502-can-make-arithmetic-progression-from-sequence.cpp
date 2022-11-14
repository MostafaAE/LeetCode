class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(1)
    */
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        
        for(int i = 2 ; i < (int)arr.size() ; i++)
            if(arr[i] - arr[i-1] != diff)
                return false;
        
        return true;
    }
};