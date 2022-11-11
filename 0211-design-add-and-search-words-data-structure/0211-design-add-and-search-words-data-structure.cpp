class WordDictionary {
private:
    map<int, WordDictionary*> child;
    bool isLeaf{};
public:
    WordDictionary() 
    {
    }
    
    void addWord(string word) 
    {
        WordDictionary *cur = this;
        for(int i = 0 ; i < (int)word.size() ; i++)
        {
            int idx = word[i] - 'a';
            if(!cur->child.count(idx))
                cur->child[idx] = new WordDictionary();
            cur = cur->child[idx];
        }
        cur->isLeaf = true;
    }
    
    bool search(string word, int start = 0) 
    {
        WordDictionary *cur = this;
        for(int i = start ; i < (int)word.size() ; i++)
        {
            if(word[i] == '.')
            {
                for(auto &[idx, ch] : cur->child)
                    if(ch->search(word, i+1))
                        return true;
                return false;
            }
            else
            {
                int idx = word[i] - 'a';
                if(!cur->child.count(idx))
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