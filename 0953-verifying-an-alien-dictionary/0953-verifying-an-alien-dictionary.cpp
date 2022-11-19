class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
        unordered_map<char, int> chToIdx;
        for(int i = 0 ; i < 26 ; i++)
            chToIdx[order[i]] = i;
        
        for(int i = 0 ; i < (int)words.size()-1 ; i++)
        {
            int size1{(int)words[i].size()}, size2{(int)words[i+1].size()};
            int minSize = min(size1, size2);
            int equalLetters{};
            
            for(int j = 0 ; j < minSize ; j++)
            {
                if(chToIdx[words[i][j]] > chToIdx[words[i+1][j]])
                    return false;
                else if (chToIdx[words[i][j]] < chToIdx[words[i+1][j]])
                    break;
                else
                    equalLetters++;
            }
            if(equalLetters == minSize && size1 > size2)
                return false;
        }
        
        return true;
    }
};