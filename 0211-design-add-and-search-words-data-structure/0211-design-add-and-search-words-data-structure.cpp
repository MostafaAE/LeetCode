class WordDictionary {
private:
    static const int MAX_CHAR = 26;
    WordDictionary *child[MAX_CHAR];
    bool isLeaf{};
public:
    WordDictionary() 
    {
        memset(child, 0, sizeof(child));
    }
    
    void addWord(string word) 
    {
        WordDictionary *cur = this;
        for(int i = 0 ; i < (int)word.size() ; i++)
        {
            int idx = word[i] - 'a';
            if(!cur->child[idx])
                cur->child[idx] = new WordDictionary();
            cur = cur->child[idx];
        }
        cur->isLeaf = true;
    }
    
    bool search(string word) 
    {
        WordDictionary *cur = this;
        for(int i = 0 ; i < (int)word.size() ; i++)
        {
            if(word[i] == '.')
            {
                for(int j = 0 ; j < MAX_CHAR ; j++)
                    if(cur->child[j] && cur->child[j]->search(word.substr(i+1)))
                        return true;
                return false;
            }
            else
            {
                int idx = word[i] - 'a';
                if(!cur->child[idx])
                    return false;
                cur = cur->child[idx];
            }
        }
        return cur->isLeaf;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */