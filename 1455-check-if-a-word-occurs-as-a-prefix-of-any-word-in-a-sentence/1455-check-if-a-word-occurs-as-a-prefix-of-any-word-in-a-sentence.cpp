class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) 
    {
        int n = sentence.size(), m = searchWord.size();
        
        int ptr1{}, ptr2{}, wordIdx{1};
        
        
        while(ptr1 < n && ptr2 < m)
        {
            while(ptr1 < n && ptr2 < m && sentence[ptr1] == searchWord[ptr2])
            {
                ++ptr1;
                ++ptr2;
            }
            
            if(ptr2 == m)
                return wordIdx;
            
            while(ptr1 < n && sentence[ptr1] != ' ')
                ++ptr1;
            
            ++wordIdx;
            ptr2 = 0;
            ++ptr1;
        }
        
        return -1;
    }
};