class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        string rep{};
        int n{(int)s.size()};
        for(int i = 0 ; i < n/2 ; i++)
        {
            rep += s[i];
            
            if((n % (i+1) == 0))
            {
                string constructed{};
                int repeats = n / (i+1);
                
                for(int j = 0 ; j < repeats ; j++)
                    constructed += rep;
                
                if(constructed == s)
                    return 1;
            }
       }
        return 0;
    }
};