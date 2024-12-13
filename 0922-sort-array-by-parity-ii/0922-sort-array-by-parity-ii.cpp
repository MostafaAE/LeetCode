class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) 
    {
        int n = nums.size(), evenIdx{}, oddIdx{1};
        vector<int> result(n);
        
        // O(n)
        for(int num : nums)
        {
            // Odd
            if(num&1)
                result[oddIdx] = num, oddIdx += 2;
            else
                result[evenIdx] = num, evenIdx += 2;
        }   
        
        return result;
    }
};