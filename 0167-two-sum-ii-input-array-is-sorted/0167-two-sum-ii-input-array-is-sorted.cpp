class Solution {
public:
    /* 
    * Approach:
    * Iterate on the array using two pointers (left, right) if the value greater than the target, shift right left
    * if the value less than the target, shift left right
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int n{(int)numbers.size()};
        int left{}, right{n-1};
        
        while(left < right)
        {
            int sum = numbers[left] + numbers[right];
            if(sum == target)
                return {left+1, right+1};
            else if(sum > target)
                right--;
            else
                left++;
        }
        
        return {};
    }
};