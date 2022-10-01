class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        priority_queue<int> pq;

        //O(nlog(n))
        for(int i = 0 ; i < (int)nums.size() ; i++)
            pq.push(-nums[i]);

        //O(nlog(n))
        for(int i = 0 ; i < (int)nums.size() ; i++)
            nums[i] = -pq.top(), pq.pop();
        
        return nums;
        
    }
};