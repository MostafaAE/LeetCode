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
    
    // Insert a word in the trie
    void insert(const string& str)
    {
        Trie *cur = this;
        for(auto c : str)
        {
            int idx = c - 'a';
            if(cur->child[idx] == nullptr)
                cur->child[idx] = new Trie();
            cur = cur->child[idx];
        }
        cur->isLeaf = true;
    }
    
    // Given a word return its shortest prefix in the trie, or the word if no matching exists
    string findWordPrefix(const string& str)
    {
        Trie *cur = this;
        for(int i = 0 ; i < str.size() ; ++i)
        {
            int idx = str[i] - 'a';
            if(cur->child[idx] == nullptr)
                break;
            
            cur = cur->child[idx];
            
            if(cur->isLeaf)
                return str.substr(0 , i + 1);
        }
        
        return str;
    }
};

class Solution {
public:
    /*
    * Approach:
    * - Construct a trie using the given dictionary of words.
    * - Insert each word from the dictionary into the trie.
    * - Split the input sentence into individual words.
    * - For each word, find the shortest prefix in the trie that matches the word.
    * - Join the processed words back into a single string.
    *
    * Complexity:
    * - Time Complexity: O(d.w + s.w), where `d` is the dictionary length, `s` is the sentence length, and `w` is the average word length.
    * - Space Complexity: O(d.w + s.w)
    */
    string replaceWords(vector<string>& dictionary, string sentence) 
    {
        Trie *trie = new Trie();
        string result{};
        vector<string> sentenceWords = split(sentence, ' ');
        
        for(auto word : dictionary)
            trie->insert(word);
        
        for(int i = 0 ; i < sentenceWords.size() ; ++i)
        {
            if(i > 0)
                result += " ";
            result += trie->findWordPrefix(sentenceWords[i]);
        }
        
        return result;
    }
    
    vector<string> split(string& str, char delim)
    {
        vector<string> words;
        stringstream ss(str);
        
        string word;
        while(getline(ss, word, delim))
            words.push_back(word);
        
        return words;
    }
};