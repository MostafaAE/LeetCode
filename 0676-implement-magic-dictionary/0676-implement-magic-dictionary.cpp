class Trie
{
private:
    static const int MAX_CHAR = 26;
    Trie *child[MAX_CHAR];
    bool isLeaf{};

public:
    Trie()
    {
        // set the child array pointers to nullptr
        memset(child, 0, sizeof(child));
    }
    
    void insert(string str)
    {
        Trie *cur = this;
        for (int i = 0; i < (int)str.size(); i++)
        {
            int ch = str[i] - 'a';

            if (!cur->child[ch])
                cur->child[ch] = new Trie();

            cur = cur->child[ch];
        }
        cur->isLeaf = true;
    }
    
    bool word_exist(string str)
    {
        Trie *cur = this;
        for (int i = 0; i < (int)str.size(); i++)
        {
            int ch = str[i] - 'a';

            if (!cur->child[ch])
                return false;

            cur = cur->child[ch];
        }
        return cur->isLeaf;
    }
    
    bool word_exist_with_1_change(string str)
    {
        for(int i = 0 ; i < (int)str.size() ; i++)
        {
            char cpy = str[i];
            for(char ch = 'a' ; ch <= 'z' ; ch++)
            {
                str[i] = ch;
                if(ch == cpy)
                    continue;
                if(word_exist(str))
                    return true;
            }
            str[i] = cpy;
        }
        return false;
    }
};

class MagicDictionary {
public:
    Trie trie;
    
    MagicDictionary() 
    {
        
    }
    
    void buildDict(vector<string> dictionary) 
    {
        
        for(string str : dictionary)
            trie.insert(str);
        
    }
    
    bool search(string searchWord) 
    {
        return trie.word_exist_with_1_change(searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */