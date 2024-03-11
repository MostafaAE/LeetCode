class Solution {
public:
    /*
     * Approach:
     * Use a hash map to count each char in s, then build a new string that match the order.
     *
     * Complexity:
     * Time Complexity : O(n) where n is the size of "s"
     * Space Complexity : O(1) => ignoring the output space and there is only 26 characters O(1)
     */
    string customSortString(string order, string s) 
    {
        string output{};
        unordered_map<char, int> freq;
        
        for(char c : s)
            freq[c]++;
        
        for(char c : order)
            if(freq[c])
                output += string(freq[c], c), freq[c] = 0;
         
    
        for(auto [c, count] : freq)
            if(count)
                output += string(count, c);
        
        return output;
    }
};