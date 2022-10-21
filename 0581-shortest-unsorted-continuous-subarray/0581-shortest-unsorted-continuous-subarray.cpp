class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(n)
    */
    int findUnsortedSubarray(vector<int>& nums) 
    {
        vector<int> sorted(nums);
        int cnt{}, size = (int)nums.size();
        bool start = 1;
        
        sort(sorted.begin(), sorted.end());
        
        for(int i =  0 ; i < (int)nums.size() ; i++)
        {
            if(nums[i] == sorted[i])
                cnt++;
            else
            {
                if(start)
                    start = 0, size -= cnt;
                
                cnt = 0;
            }
        }
        
        return size - cnt;
    }
};