class Solution {
public:
     /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    char findTheDifference(string s, string t) 
    {
        int sum{t[(int)t.size()-1]};
        
        for(int i = 0 ; i < (int)s.size() ; i++)
            sum += t[i] - s[i];
        
        return sum;
    }
};