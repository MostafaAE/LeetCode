class Solution {
public:
    /**
     * Approach:
     * - Initialize a queue with all friends numbered from 1 to n.
     * - Simulate the process k-1 times and removing the k-th friend.
     * - Continue the process until only one friend is left.
     * - The last remaining friend is the winner.
     *
     * Complexity:
     * - Time Complexity: O(n*k)
     * - Space Complexity: O(n)
     */
    int findTheWinner(int n, int k) 
    {
        queue<int> friends;
        
        for(int i = 1 ; i <= n ; ++i)
            friends.push(i);
        
        while(friends.size() > 1)
        {
            for (int i = 0; i < k - 1; i++) 
            {
                friends.push(friends.front());
                friends.pop();
            }
            
            friends.pop();
        }
        
        return friends.front();
    }
};