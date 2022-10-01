class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> answer;
        
        pq.push(make_pair(nums[0], 0));
        if(k == 1)
            answer.push_back(nums[0]);
        
        for(int i = 1 ; i < (int)nums.size() ; i++)
        {
            while(!pq.empty() && i-pq.top().second >= k)
                pq.pop();
            
            if(!pq.empty() && nums[i] >= pq.top().first)
            {
                while(!pq.empty())
                    pq.pop();
            }
            
            pq.push(make_pair(nums[i],i));
            
            if(i >= k-1)
                answer.push_back(pq.top().first);
        }
        
        return answer;
    }
};