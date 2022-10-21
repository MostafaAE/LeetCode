class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int idx{}, sum{};
        
        while(k)
        {
            if(nums[idx] == 0)
                break;
            if(nums[idx] > 0)
            {
                if(k%2)
                {
                    // we have two cases
                    // the previous element was a -ve and we made it +ve
                    // or this is the first element
                    if(idx > 0 && nums[idx-1] < nums[idx])
                        idx--;
                    
                    nums[idx] = -nums[idx];
                }
                break;
            }
            else
                nums[idx] = -nums[idx];
            
            k--; 
            if(idx+1 < nums.size())
                idx++;
        }
        
        for(int i = 0 ; i < (int)nums.size() ; i++)
            sum+= nums[i];
        
        return sum;
    }
};