class Solution {
public:
    /* 
    * Approach:
    * Breadth first search.
    * 
    * Complexity:
    * Time Complexity : O(LN^2)
    * Space Complexity : O(N) where L is the length of the word and N is the length of wordList
    */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {   
        auto it = find(wordList.begin(), wordList.end(), endWord);
        if(it == wordList.end())
            return 0;
        
        wordList.push_back(beginWord);
        
        // prepare the adj list
        unordered_map<string, vector<string>> patternToWords;
        for(string word : wordList)
        {
            for(int i = 0 ; i < (int)word.size() ; i++)
            {
                string pattern = word;
                pattern[i] = '*';
                if(!patternToWords.count(pattern))
                    patternToWords[pattern] = vector<string>();
                patternToWords[pattern].push_back(word);
            }
        }
        
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        
        int level{1};
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                string cur = q.front();
                q.pop();
                
                for(int i = 0 ; i < (int)cur.size() ; i++)
                {
                    string pattern = cur;
                    pattern[i] = '*';
                    for(string word : patternToWords[pattern])
                    {
                        if(!visited.count(word))
                        {
                            if(word == endWord)
                                return level + 1;

                            q.push(word);
                            visited.insert(word);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};