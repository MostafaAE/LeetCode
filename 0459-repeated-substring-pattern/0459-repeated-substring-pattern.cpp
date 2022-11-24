class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        int n{(int)s.size()};
        
        for(int i = n/2 ; i >= 1 ; i--)
        {
            // i is expressing the size of the substring forming
            // if length of the substring(i.e, i) divides n equally then we can say the substring can be/may be a possible solution
            // so we check further,else we skip.
            if((n % i == 0)) 
            {
                //rotation approach-->if two substrings from first and last match then we can say they can repeatedly form the string.
                if(s.substr(0, n-i) == s.substr(i)) 
                    return 1;
            }
        }
        return 0;
    }
};