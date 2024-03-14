class Solution {
public:
    /* 
    * Approach:
    * Breadth first search.
    * 
    * Complexity:
    * Total number of states = O(D) = 8
    * Time Complexity : O(4*D * 4^D) << constant 
    * Space Complexity : O(4^D) << constant 
    */
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        unordered_set<string> visited;
        unordered_set<string> validMutations(bank.begin(), bank.end());
        
        // invalid end
        if(!validMutations.count(endGene))
            return -1;
        
        string mutations = "ACGT";
        const int D = 8; // number of characters
        
        queue<string> q;
        validMutations.insert(startGene);
        
        if(process(q, startGene, endGene, visited, validMutations))
            return 0;
        
        int level = 0;
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                string cur = q.front();
                q.pop();
                
                for(int i = 0 ; i < D ; i++)
                {
                    string temp = cur;
                    for(int j = 0 ; j < mutations.size() ; j++)
                    {
                        temp[i] = mutations[j];
                        if(process(q, temp, endGene, visited, validMutations))
                            return level + 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
    
    bool process(queue<string>& q, string& curGene, string& endGene, unordered_set<string>& visited, unordered_set<string>& validMutations)
    {
        if(curGene == endGene)
            return true;
        
        if(validMutations.count(curGene) && !visited.count(curGene))
        {
            visited.insert(curGene);
            q.push(curGene);
        }
        
        return false;
    }
};