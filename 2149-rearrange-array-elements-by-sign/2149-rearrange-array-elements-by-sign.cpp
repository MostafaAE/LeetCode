class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        int n = nums.size(), positiveIdx{}, negativeIdx{1};
        vector<int> rearranged(n);

        for(int num : nums)
        {
            if(num > 0)
            {
                rearranged[positiveIdx] = num;
                positiveIdx += 2;
            }
            else
            {
                rearranged[negativeIdx] = num;
                negativeIdx += 2;
            }
        }

        return rearranged;
    }
};