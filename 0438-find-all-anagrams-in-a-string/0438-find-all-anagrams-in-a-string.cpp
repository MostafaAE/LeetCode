class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n) where n is "s.length"
    * Space Complexity : O(1) => neglecting the output space
    */
    vector<int> findAnagrams(string s, string p)
    {
        if((int)p.size() > (int)s.size())
            return {};
        
        vector<int> result;
        int slen{(int)s.size()}, plen{(int)p.size()};
        int pFreq[26]{}, windowFreq[26]{};
        
        // O(m)
        for(int i = 0 ; i < plen ; i++)
        {
            pFreq[p[i] - 'a']++;
            windowFreq[s[i] - 'a']++;
        }
        if(isAnagram(pFreq, windowFreq))
            result.push_back(0);
        
        // O(n)
        for (int i = plen; i < slen; i++)
        {
            windowFreq[s[i] - 'a']++;
            windowFreq[s[i-plen] - 'a']--;
            
            //O(1)
            if(isAnagram(pFreq, windowFreq))
                result.push_back(i-plen+1);
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