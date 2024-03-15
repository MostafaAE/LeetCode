class Solution {
public:
    /*
     * Approach:
     * Compute prefix and suffix product for each index, answer[i] = prefix prod * suffix prod
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(1) => ignoring the output space
     */
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n{(int)nums.size()}, prefixProd{1};
        vector<int> answer(n, 1);
        
        // compute the suffix product for each number
        answer[n-1] = nums[n-1];
        for(int i = n-2 ; i >= 0 ; i--)
            answer[i] = nums[i] * answer[i + 1];
        
        // answer[i] = prefix product * suffix product
        for(int i = 0 ; i < n -1 ; i++)
        {
            answer[i] = prefixProd * answer[i + 1];
            prefixProd *= nums[i];
        }
        answer[n-1] = prefixProd;
        
        return answer;
    }
};