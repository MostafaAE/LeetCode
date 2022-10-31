class Solution {
public:
    /* 
    * Approach:
    * iterate on each element and binary search the difference between the target and the element
    * 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(1)
    */
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        for(int i = 0 ; i < (int)numbers.size() ; i++)
        {
            int diff = target - numbers[i];
            
            auto ub = upper_bound(numbers.begin(), numbers.end(), diff);
            ub--;
            int ubIdx = ub-numbers.begin();
            
            if(*ub == diff && ubIdx != i)
                return {i+1, ubIdx+1};
        }
        return {0, 0};
    }
};