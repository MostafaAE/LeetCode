class NumArray {
public:
    
    vector<int> NumArr;
    
    // O(n)
    NumArray(vector<int>& nums) 
    {
        NumArr = nums;
        for(int i = 1 ; i < (int)nums.size() ; i++)
            NumArr[i] += NumArr[i-1];
    }
    
    // O(1)
    int sumRange(int left, int right) 
    {
        if(left == 0)
            return NumArr[right];
        else
            return NumArr[right] - NumArr[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */