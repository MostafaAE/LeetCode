class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        vector<vector<int>> result;
        unordered_map<int, int> numToCount;

        for(int num : nums)
        {
            int bucketIndex = numToCount[num];
            if(result.size() == bucketIndex)
                result.push_back(vector<int>());

            result[bucketIndex].push_back(num);
            ++numToCount[num];
        }
        
        return result;
    }
};