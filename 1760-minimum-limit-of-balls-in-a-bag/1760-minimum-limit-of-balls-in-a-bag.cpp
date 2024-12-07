class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) 
    {        
        int start{1}, result{};
        int end = *max_element(nums.begin(), nums.end());

        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            
            if(checkNumOfOperations(nums, mid, maxOperations))
            {
                result = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        
        return result;
    }
    
    int checkNumOfOperations(vector<int>& nums, int num, int maxOperations)
    {
        int n = nums.size(), count{};
        
        for(int i = 0 ; i < n ; ++i)
        {
            count += ceil((double)nums[i] / num) - 1;
            
            if(count > maxOperations)
                return false;
        }
        
        return true;
    }
};