class Solution {
public:
    /* 
    * Approach:
    * Use max heap to keep track of the sliding window maximum
    * 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(n)
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        priority_queue<pair<int, int>> pq;
        vector<int> output;
        
        pq.push({nums[0], 0});
        
        for(int i = 1 ; i < k ; i++)
            pq.push({nums[i], i});
        
        output.push_back(pq.top().first);
        
        for(int i = k ; i < (int)nums.size() ; i++)
        {
            pq.push({nums[i], i});
            while(pq.top().second <= i - k)
                pq.pop();
            
            output.push_back(pq.top().first); 
        }
        
        return output;
    }        
};