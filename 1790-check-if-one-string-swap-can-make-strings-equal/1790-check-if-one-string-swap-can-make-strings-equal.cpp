class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    bool areAlmostEqual(string s1, string s2) 
    {
        int count1[26]{};
        int count2[26]{};
        int outOfPosition{};
        
        for(int i = 0 ; i < (int)s1.size() ; i++)
        {
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
            
            if(s1[i] != s2[i])
                outOfPosition++;
        }
        
        for(int i = 0 ; i < 26 ; i++)
            if(count1[i] != count2[i])
                return false;

        return outOfPosition <= 2;
    }
};