class Trie {
private:
    static const int MAX_CHAR = 26;
    Trie *child[MAX_CHAR];
    bool isLeaf{};
public:
    Trie() 
    {
        memset(child, 0, sizeof(child));
        
    }
    
    // O(L)
    void insert(string word) 
    {
        Trie *cur = this;
        for(int i = 0 ; i < (int)word.size() ; i++)
        {
            int idx = word[i] - 'a';
            if(!cur->child[idx])
                cur->child[idx] = new Trie();
            cur = cur->child[idx];
        }
        cur->isLeaf = true;
    }
    
    // O(L)
    bool search(string word) 
    {
        Trie *cur = this;
        for(int i = 0 ; i < (int)word.size() ; i++)
        {
            int idx = word[i] - 'a';
            if(!cur->child[idx])
                return false;
            cur = cur->child[idx];
        }
        return cur->isLeaf; 
    }
    
    // O(L)
    bool startsWith(string prefix) 
    {
        Trie *cur = this;
        for(int i = 0 ; i < (int)prefix.size() ; i++)
        {
            int idx = prefix[i] - 'a';
            if(!cur->child[idx])
                return false;
            cur = cur->child[idx];
        }
        return true; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */