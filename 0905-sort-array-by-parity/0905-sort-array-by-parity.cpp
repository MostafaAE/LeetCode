class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int n = nums.size(), left{}, right{n-1};
        vector<int> result(n);
        
        // O(n)
        for(int num : nums)
        {
            // Odd
            if(num&1)
                result[right--] = num;
            else
                result[left++] = num;
        }   
        
        return result;
    }
};