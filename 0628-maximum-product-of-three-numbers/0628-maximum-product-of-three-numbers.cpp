class Solution {
public:
    /* 
    * Approach: 
    * Utilize a min heap to get the largest 3 numbers, and max heap to get the smallest 2 numbers, then return the maximum 
    * product of 3 numbers (this could be the 3 largest +ve numbers or the 2 smallest -ve numbers and the largest +ve number).
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int maximumProduct(vector<int>& nums) 
    {
        int n{(int)nums.size()};
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i = 0 ; i < n ; i++)
        {
            maxHeap.push(nums[i]);
            minHeap.push(nums[i]);
            
            if(minHeap.size() > 3)
                minHeap.pop();
            if(maxHeap.size() > 2)
                maxHeap.pop();
        }
        
        // now the min heap have the largest 3 numbers and the max heap have the smallest 2 numbers
        int result1 = 1, result2 = 1;
        for(int i = 0 ; i < 2 ; ++i)
        {
            result1 *= minHeap.top(), minHeap.pop();
            result2 *= maxHeap.top(), maxHeap.pop();
        }
        
        int maxValue = minHeap.top();
        return max(maxValue * result1, maxValue * result2);
    }
};