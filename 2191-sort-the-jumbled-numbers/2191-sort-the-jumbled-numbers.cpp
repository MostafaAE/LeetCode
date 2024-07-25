class Solution {
public:
    /**
     * Approach:
     * - Create a mapping from each digit to its corresponding value using the provided mapping vector.
     * - For each number in the input nums, convert it to its mapped value using the digit-to-value mapping.
     * - Store the original numbers in a map where the key is the mapped value.
     * - Sort the map keys, and then reconstruct the sorted array using the original numbers stored in the map.
     * 
     * Complexity:
     * - Time Complexity: O(n logn), where n is the number of elements in nums.
     * - Space Complexity: O(n)
     */
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) 
    {
        map<int, vector<int>> mappedToVal;
        unordered_map<int, int> valToMapping;
        vector<int> result;
        
        for(int i = 0 ; i < mapping.size() ; ++i)
            valToMapping[i] = mapping[i];
        
        for(int i = 0 ; i < nums.size() ; ++i)
        {
            int mappedNum = mapNum(nums[i], valToMapping);
            mappedToVal[mappedNum].push_back(nums[i]);
        }
        
        for(auto [mapped, vals] : mappedToVal)
            result.insert(result.end(), vals.begin(), vals.end());

        return result;
    }
    
    int mapNum(int num, unordered_map<int, int>& valToMapping)
    {
        string str = to_string(num);
        string mapped = "";
        for(int i = 0 ; i < str.size() ; ++i)
            mapped += valToMapping[str[i]-'0']+'0';
        return stoi(mapped);
    }
};