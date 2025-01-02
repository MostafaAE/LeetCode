class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        int numsLessThanPivot{}, numsEqualToPivot{};
    
        for(int num : nums)
        {
            if(num < pivot)
                ++numsLessThanPivot;
            else if(num == pivot)
                ++numsEqualToPivot;
        }

        int lessThanItr{}, equalItr = numsLessThanPivot, greaterThanItr = numsLessThanPivot + numsEqualToPivot;
        vector<int> result(nums.size());
        for(int num : nums)
        {
            if(num < pivot)
                result[lessThanItr++] = num;
            else if(num == pivot)
                result[equalItr++] = num;
            else
                result[greaterThanItr++] = num;
        }

        return result;
    }
};