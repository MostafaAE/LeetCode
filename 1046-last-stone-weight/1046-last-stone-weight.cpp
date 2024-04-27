class Solution {
public:
    /*
     * Approach:
     * Use a max heap to simulate the process of smashing stones.
     * 1. Insert all the stones into the max heap.
     * 2. While there are at least two stones in the heap, extract the two heaviest stones from the heap and smash them together.
     * 3. After the loop, if the heap is empty, return 0; otherwise, return the weight of the remaining stone.
     *
     * Complexity:
     * Time Complexity: O(n logn)
     * Space Complexity: O(n)
     */
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> maxHeap;
        
        for(auto stone : stones)
            maxHeap.push(stone);
        
        while(maxHeap.size() > 1)
        {
            auto heaviest1 = maxHeap.top();
            maxHeap.pop();
            auto heaviest2 = maxHeap.top();
            maxHeap.pop();
            
            if(heaviest1 != heaviest2)
                maxHeap.push(abs(heaviest1 - heaviest2));
        }
        
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};