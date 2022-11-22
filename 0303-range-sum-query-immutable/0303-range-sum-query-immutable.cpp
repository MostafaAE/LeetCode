class NumArray {
public:
    
    vector<int> cumSum;
    
    // O(n)
    NumArray(vector<int>& nums): cumSum(nums)
    {
        for(int i = 1 ; i < (int)cumSum.size() ; i++)
            cumSum[i] += cumSum[i-1];
    }
    
    // O(1)
    int sumRange(int left, int right) 
    {
        if(left == 0)
            return cumSum[right];
        else
            return cumSum[right] - cumSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */