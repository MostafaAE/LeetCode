class Solution {
public:
    /*
     * Approach
     * Each ith person before `k` will go in the queue `min(tickets[k], tickets[i]) times`
     * Each ith person after `k` will take go in the queue `min(tickets[k]-1, tickets[i]) times`
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(1)
     */
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        int time{};
        
        for(int i = 0 ; i < (int)tickets.size() ; i++)
        {
            if(i <= k)
                time += min(tickets[k], tickets[i]);
            else
                time += min(tickets[k]-1, tickets[i]);
        }
        return time;
    }
};