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

    string firstWordPrefix(const string &str)
    {
        Trie *cur = this;

        for (int i = 0; i < (int)str.size(); i++)
        {

            int ch = str[i] - 'a';

            if (!cur->child[ch])
                break;

            cur = cur->child[ch];

            if (cur->isLeaf)
                return str.substr(0, i + 1);
        }
        return str;
    }
};

class Solution {
public:
    
    //split string at certain delimeter
    vector<string> split(const string &s, char delim)
    {
        vector<string> result;
        stringstream ss(s);
        string item;

        while (getline(ss, item, delim))
        {
            result.push_back(item);
        }

        return result;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) 
    {
        Trie trie;
        vector<string> words = split(sentence, ' ');
        string result = "";
        for(string s : dictionary)
            trie.insert(s);
        
        for(int i = 0 ; i < (int)words.size() ; i++)
        {
            result += trie.firstWordPrefix(words[i]);
            if(i < (int) words.size() - 1)
                result += " ";
        }
        
        return result;
            
    }
};