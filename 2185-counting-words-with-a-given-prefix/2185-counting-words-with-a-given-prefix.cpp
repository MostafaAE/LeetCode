class Trie
{
public:
    static const int MAX_CHAR = 26;
    Trie *child[MAX_CHAR];
    bool isLeaf{};
    int count{}; // Number of words passing through this node

    Trie() 
    {
        memset(child, 0, sizeof(child));
        isLeaf = false;
        count = 0;
    }

    void insert(string s)
    {
        Trie* cur = this;
        for (int i = 0; i < s.size(); ++i)
        {
            int idx = s[i] - 'a';
            if (cur->child[idx] == nullptr)
                cur->child[idx] = new Trie();

            cur = cur->child[idx];
            ++cur->count;
        }
        cur->isLeaf = true;
    }

    int findPrefixCount(string s)
    {
        Trie* cur = this;
        for (int i = 0; i < s.size(); ++i)
        {
            int idx = s[i] - 'a';
            if (cur->child[idx] == nullptr)
                return 0; // Prefix does not exist

            cur = cur->child[idx];
        }
        return cur->count;
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) 
    {
        Trie trie;

        for (string word : words)
            trie.insert(word);

        return trie.findPrefixCount(pref);
    }
};