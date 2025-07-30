class Solution {
public:
    string decodeMessage(string key, string message) 
    {
        unordered_map<char, char> keyToOriginal { {' ', ' '}};
        char cur = 'a';
        
        for(char c : key)
        {
            if(!keyToOriginal.count(c))
            {
                keyToOriginal[c] = cur++;
            }

            if(keyToOriginal.size() == 27)  // 26 letters + space
                break;
        }

        string result;
        result.reserve(message.size());

        for(char c : message)
        {
            result += keyToOriginal[c];
        }

        return result;
    }
};