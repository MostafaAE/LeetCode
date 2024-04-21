class Solution {
public:
    /*
     * Approach:
     * Iterate through the senate string and enqueue each senator into a queue.
     * Count the total number of Radiants and Dires senators.
     * Then, simulate the voting process by iterating through the queue until either
     * all Radiants or all Dires are eliminated.
     *
     * Complexity:
     * Time Complexity: O(n^2)
     * Space Complexity: O(n)
     */
    string predictPartyVictory(string senate) 
    {
        queue<char> q;
        int totalRadiants = 0, totalDires = 0, radiantsVotes = 0, diresVotes = 0;
        
        for(char c : senate)
        {
            q.push(c);
            totalRadiants += (c == 'R');
            totalDires += (c == 'D');
        }
        
        while(totalRadiants && totalDires)
        {            
            char cur = q.front();
            q.pop();

            if(cur == 'R')
            {
                if(!diresVotes)
                    radiantsVotes++, q.push(cur);
                else
                    totalRadiants--, diresVotes--;
            }
            else 
            {
                if(!radiantsVotes)
                    diresVotes++, q.push(cur);
                else
                    totalDires--, radiantsVotes--;
            }
        }
        
        if(!totalRadiants)
            return "Dire";
        return "Radiant";
    }
};
