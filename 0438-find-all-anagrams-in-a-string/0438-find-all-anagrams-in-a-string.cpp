class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(m*n) where m is "s.length", and n is "p.length"
    * Space Complexity : O(n) => neglecting the output space
    */
    vector<int> findAnagrams(string s, string p)
    {
        if((int)p.size() > (int)s.size())
            return {};
        
        vector<int> result;
        int slen{(int)s.size()}, plen{(int)p.size()};
        int pFreq[26]{};
        
        // O(n)
        for(int i = 0 ; i < plen ; i++)
            pFreq[p[i] - 'a']++;
        
        for (int i = 0; i <= slen - plen; i++)
        {
            int subFreq[26]{};
            string sub = s.substr(i, plen);
            
            // sub length will always be equal to p length
            //O(m)
            for(int j = 0 ; j < plen ; j++)
                subFreq[sub[j] - 'a']++;
            
            //O(1)
            if(isAnagram(pFreq, subFreq))
                result.push_back(i);
        }
        
        return result;
    }
    
    bool isAnagram(int aFreq[], int bFreq[])
    {
        for(int i = 0 ; i < 26 ; i++)
            if(aFreq[i] != bFreq[i])
                return false;
        return true;
    }
};