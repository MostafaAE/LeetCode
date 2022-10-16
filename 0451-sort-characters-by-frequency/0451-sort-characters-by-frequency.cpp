class Solution {
public:
    
    /* 
    * Approach:
    * store each character and its frequency in an array, then sort the array in
    * decreasing order, and finally reconstruct the string again
    * 
    * Complexity: 
    * Time Complexity : O(L) where L is the length of the input string
    * Space Complexity : O(1) >> neglecting the output space
    */
    string frequencySort(string s) 
    {
        vector<pair<int,int>> freq(62, {0,0});
        string result="";
        
        // O(L)
        for(char c : s)
        {
            int val;
            if(islower(c))
                val = c - 'a';
            
            else if (isupper(c))
                val = c - 'A' + 26;
            
            else
                val = c - '0' + 52;
            
            freq[val].first++;
            freq[val].second = c;
        }
        
        // O(1) >> the vector is fixed size (62 elements only) so O(62*log(62))
        sort(freq.begin(), freq.end(), greater<pair<int,int>>());
        
        // O(L)
        for(auto [f, c] : freq)
            result += string(f, c);
        
        return result;
        
    }
};