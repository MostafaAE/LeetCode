class Solution {
public:
    /* 
    * Approach:
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(n)
    */
    bool checkIfExist(vector<int>& arr) 
    {
        unordered_set<int> s;
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0 ; i < (int)arr.size() ; i++)
        {
            if(s.count(arr[i]))
                return true;
            
            if(arr[i] < 0 && arr[i]%2 == 0)
                s.insert(arr[i]/2);
            else
                s.insert(arr[i]*2);
        }
            
        return false;
    }
};