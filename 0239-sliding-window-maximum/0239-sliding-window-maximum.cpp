class Solution {
public:
    /* 
    * Approach:
    * - Use a monotonically decreasing queue to track the sliding window maximum `O(N)`
    * - We can also use max heap to keep track of the sliding window maximum `O(NlogK)`
    * 
    * Complexity:
    * Time Complexity : O(N)
    * Space Complexity : O(K) => ignoring output space
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
            
            if(i >= k - 1)
                output.push_back(nums[dq.front()]);
        }
        
        return output;
    }        
};