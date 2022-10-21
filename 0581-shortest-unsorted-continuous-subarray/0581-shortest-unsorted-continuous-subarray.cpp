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
        int start {-1}, end{-1};
        
        sort(sorted.begin(), sorted.end());
        
        for(int i =  0 ; i < (int)nums.size() ; i++)
        {
            if(nums[i] != sorted[i])
            {
                if(start == -1)
                    start = i;
                else
                    end = i;
            }
        }
        if(start == -1)
            return 0;
        
        return end-start+1;
    }
};