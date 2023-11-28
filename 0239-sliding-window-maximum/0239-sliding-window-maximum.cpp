class Solution {
public:
    /* 
    * Approach:
    * Use monotonic decreasing queue to track the sliding window maximum
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> output;
        
        for(int i = 0 ; i < (int)nums.size() ; i++)
        {
            while(!dq.empty() && nums[i] > nums[dq.back()])
                dq.pop_back();
            
            
            dq.push_back(i);
            if(dq.front() <= i-k)
                dq.pop_front();
            
            if(i - k >= -1)
                output.push_back(nums[dq.front()]);
        }
        
        return output;
    }        
};