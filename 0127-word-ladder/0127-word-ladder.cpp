class Solution {
public:
    /* 
    * Approach:
    * Breadth first search.
    * 
    * Complexity:
    * Time Complexity : O(NM^2)
    * Space Complexity : O(N) where M is the length of the word and N is the length of wordList
    */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {   
        unordered_set<string> hashSet(wordList.begin(), wordList.end());
        if(!hashSet.count(endWord))
            return 0;
        
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
                string curWord = q.front();
                q.pop();
                
                for(int i = 0 ; i < (int)curWord.size() ; i++)
                {
                    for(char c = 'a' ; c <= 'z' ; c++)
                    {
                        string word = curWord;
                        word[i] = c;
                        if(!visited.count(word) && hashSet.count(word))
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