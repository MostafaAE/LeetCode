class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        // O(n) heapify
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        
        // O(k logn)
        while(k--)
        {
            int maxPile = maxHeap.top();
            maxHeap.pop();
            
            maxHeap.push(sqrt(maxPile));
        }
        
        // O(n logn)
        long long result{};
        while(!maxHeap.empty())
            result += maxHeap.top(), maxHeap.pop();
        
        return result;
    }
};