class Solution {
public:
    /* 
    * Approach:
    * Utilize a priority queue as a min heap and use it to keep track of the k largest elements, the answer will be the top of it.
    * Complexity:
    * Time Complexity : O(nlogk)
    * Space Complexity : O(k)
    */
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int, vector<int>, greater<int>> mnHeap;
        
        for(int val : nums)
        {
            if(mnHeap.size() >= k && val >= mnHeap.top())
                mnHeap.pop();
            
            if(mnHeap.size() < k)
                mnHeap.push(val);
        }    
        return mnHeap.top();
    }
};