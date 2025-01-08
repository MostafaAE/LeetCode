class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) 
    {
        unordered_set<int> distinctNums(nums.begin(), nums.end());
        
        for(int num : nums)
            distinctNums.insert(reverseInteger(num));

        return distinctNums.size();
    }

    int reverseInteger(int num)
    {
        int reversed{};
        while(num > 0)
        {
            reversed *= 10;
            reversed += num % 10;
            num /= 10;
        }

        return reversed;
    }
};