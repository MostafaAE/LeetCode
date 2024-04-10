class Solution {
public:
    /*
     * Approach
     * Simulation with queue
     * We can simulate the revealing process using a queue of indices to find the order the indices will be revealed. We do this by removing the front card from the queue and then moving the next index in the queue to the back.
     * We can add cards to the result as we simulate the revealing process with the queue. Each time we remove an index from the queue to reveal a card, we add the next card from the deck to the result at that index.
     *
     * Complexity:
     * Time Complexity : O(nlogn)
     * Space Complexity : O(n)
     */
    vector<int> deckRevealedIncreasing(vector<int>& deck) 
    {
        int n{(int)deck.size()};
        vector<int> result(n, 0);
        queue<int> q;
        
        for(int i = 0 ; i < n ; i++)
            q.push(i);
        
        sort(deck.begin(), deck.end());
        
        for(int i = 0 ; i < n ; i++)
        {
            result[q.front()] = deck[i];
            q.pop();
            
            if(!q.empty())
                q.push(q.front()), q.pop();
        }
        
        return result;
    }
};