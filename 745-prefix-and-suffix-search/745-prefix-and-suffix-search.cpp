class Trie
{
private:
    static const int MAX_SIZE = 26;
    Trie *child[MAX_SIZE];
    vector<int> indecies;

public:
    Trie()
    {
        memset(child, 0, sizeof(child));
    }

    void insert(string str, int idx)
    {
        Trie *cur = this;
        for (int i = 0; i < (int)str.size(); i++)
        {
            int ch = str[i] - 'a';
            if (!cur->child[ch])
                cur->child[ch] = new Trie();

            cur->child[ch]->indecies.push_back(idx);

            cur = cur->child[ch];
        }
    }

    vector<int> get_indecies(string str)
    {
        Trie *cur = this;
        for (int i = 0; i < (int)str.size(); i++)
        {
            int ch = str[i] - 'a';
            if (!cur->child[ch])
                return vector<int>();

            cur = cur->child[ch];
        }
        return cur->indecies;
    }
};

class WordFilter
{
public:
    Trie trie;
    vector<string> words;

    WordFilter(vector<string> &words)
    {
        this->words = words;
        set<string> uniqueWords;
        for (int i = (int)words.size() - 1; i >= 0; i--)
        {
            // Check if it is a unique word
            // Many words are duplicate. Let's only keep ones with high index
            // Use set to filter existing ones
            if (uniqueWords.insert(words[i]).second)
                trie.insert(words[i], i);
        }
    }

    bool isSuffix(string word, string suff)
    {
        if ((int)suff.size() > (int)word.size())
            return false;

        int wordIdx = (int)word.size() - 1;
        for (int i = suff.size() - 1; i >= 0; i--, wordIdx--)
        {
            if (suff[i] != word[wordIdx])
                return false;
        }
        return true;
    }

    int f(string pref, string suff)
    {
        // this will contain the indecies of all valid words of the prefix
        vector<int> indecies = trie.get_indecies(pref);

        for (int idx : indecies)
        {
            if (isSuffix(words[idx], suff))
                return idx;
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */