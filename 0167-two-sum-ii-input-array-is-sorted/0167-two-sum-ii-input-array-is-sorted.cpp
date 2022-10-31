class Solution {
public:
    /* 
    * Approach:
    * iterate on the array using two pointers (start, end)
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int start{}, end{(int)numbers.size()-1};
        
        while(start < end)
        {
            int sum =  numbers[start] + numbers[end];
            
            if (sum > target)
                end--;
            else if (sum < target)
                start++; 
            else
                break;
        }
    
        return {start+1, end+1};
    }
};