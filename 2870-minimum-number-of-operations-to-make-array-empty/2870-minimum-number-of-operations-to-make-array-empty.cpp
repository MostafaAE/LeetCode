class Solution {
public:
    /* 
    * Approach:
    * Utilize a hashmap to count the occurence of each number
    * if any number count = 1 return -1
    * else get the min num of operations to remove its count
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    int minOperations(vector<int>& nums) 
    {
        int numOperations{};
        unordered_map<int, int> numToCount;
        
        for(auto num : nums)
            numToCount[num]++;
        
        for(auto [num, count] : numToCount)
        {
            if(count == 1)
                return -1;
            numOperations += ceil(count / 3.0);
        }
        
        return numOperations;
    }
};