long long globalInv;
vector<int> temp;
class Solution {
public:
    /* 
    * Approach: 
    * use merge sort to find the global inversions and compare them to local inversions
    *
    * Complexity:
    * Time Complexity : O(nlog(n))
    * Space Complexity : O(n)
    */
    bool isIdealPermutation(vector<int>& nums) 
    {
        globalInv = 0;
        temp = nums;
    
        int localInv = numLocalInversions(nums);
        mergeSort(nums, 0, (int)nums.size()-1);
        
        return globalInv == localInv;
    }
    
    // O(nlog(n))
    void mergeSort(vector<int> &nums, int start, int end)
    {
        if(start >= end)
            return;
        
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
    
    void merge(vector<int> &nums, int start, int mid, int end)
    {
        for(int i = start, j = mid+1, k = start; k <= end ; k++)
        {
            if(i > mid)
                temp[k] = nums[j++];
            else if (j > end)
                temp[k] = nums[i++];
            else if (nums[i] < nums[j])
                temp[k] = nums[i++];
            else
            {
                globalInv+= j-k;
                temp[k] = nums[j++];     
            }
        }
        
        for(int i = start ; i <= end ; i++)
            nums[i] = temp[i];
    }
    
    
    // O(n)
    int numLocalInversions(vector<int>& nums)
    {
        int count{};
        
        for(int i = 0 ; i < (int)nums.size() - 1 ; i++)
            if(nums[i] > nums[i + 1])
                count++;
        return count;
    }
};
