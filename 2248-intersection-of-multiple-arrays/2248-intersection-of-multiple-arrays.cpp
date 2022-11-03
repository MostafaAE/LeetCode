class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(m*n) where m number of rows and n number of columns
    * Space Complexity : O(n^2)
    */
    vector<int> intersection(vector<vector<int>>& nums) 
    {
        int size{(int)nums.size()};
        vector<int> result;
        unordered_map<int, int> valToCount;
        
        for(int i = 0 ; i < size ; i++)
            for(int j = 0 ; j < (int)nums[i].size() ; j++)
                valToCount[nums[i][j]]++;
        
        for(auto [value, count] : valToCount)
            if(count == size)
                result.push_back(value);
        
        sort(result.begin(), result.end());
        
        return result;
    }
};