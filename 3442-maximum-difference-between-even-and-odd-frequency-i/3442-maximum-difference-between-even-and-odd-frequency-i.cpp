class Solution {
public:
    /*
     * Approach:
     * - Count the frequency of each character in the string using a frequency array of size 26.
     * - Iterate through the frequencies:
     *     - Track the **maximum odd frequency** (`maxOdd`)
     *     - Track the **minimum non-zero even frequency** (`minEven`)
     * - Return the difference: maxOdd - minEven
     *
     * Time Complexity : O(n)
     * Space Complexity: O(1)
     */
    int maxDifference(string s) 
    {
        int charCount = 26;
        vector<int> freq(charCount, 0);

        // Count frequency of each character
        for(char c : s)
        {
            ++freq[c - 'a'];
        }

        int maxOdd = INT_MIN, minEven = INT_MAX;

        // Find max odd and min even frequency
        for(int i = 0 ; i < charCount ; ++i)
        {
            if(freq[i] & 1)  // odd frequency
            {
                maxOdd = max(maxOdd, freq[i]);
            }
            else if(freq[i] > 0)  // non-zero even frequency
            {
                minEven = min(minEven, freq[i]);
            }
        }

        return maxOdd - minEven;
    }
};