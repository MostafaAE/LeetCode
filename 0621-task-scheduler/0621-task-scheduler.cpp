class Solution {
public:
    /* 
    * Approach:
    * Count the frequency of each char, put all the frequencies in a max heap (lowest time, highest frequency)
    * Each time pop an element from the heap and update its time and frequency and insert it again till the heap becomes empty.
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1) => O(26) constant
    */
    int leastInterval(vector<char>& tasks, int n) 
    {
        priority_queue<pair<int, int>> maxHeap;
        unordered_map<int, int> count;
        int intervals{1};
        
        for(char c : tasks)
            count[c]++;
        
        for(auto &[key, val] : count)
            maxHeap.push({-1, val});
        
        while(!maxHeap.empty())
        {
            auto p = maxHeap.top();
            maxHeap.pop();
            
            if(--(p.second))
                p.first -= (n + 1), maxHeap.push(p);
            
            if(!maxHeap.empty())
                intervals = max(-1 * maxHeap.top().first, intervals + 1);
        }
        
        return intervals;
    }
};