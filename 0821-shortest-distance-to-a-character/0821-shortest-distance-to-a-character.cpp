class Solution {
public:
    /**
     * Approach:
     * - First, store the indices of all occurrences of the character `c` in the string `s`.
     * - Then, iterate over the string and for each character, calculate the minimum distance to the nearest occurrence of `c`.
     * - Use two pointers (`prev` and `next`) to keep track of the nearest occurrences of `c` before and after the current index.
     * - Update these pointers as you move through the string.
     * 
     * Complexity:
     * - Time Complexity: O(n) where `n` is the length of the string `s`.
     * - Space Complexity: O(k) where `k` is the number of occurrences of `c` in the string (to store their indices).
     */
    vector<int> shortestToChar(string s, char c) 
    {
        int n = s.size();
        vector<int> occurrences, result(n);
        
        // Store the indices of all occurrences of the character c
        for(int i = 0; i < n; ++i)
            if(s[i] == c)
                occurrences.push_back(i);
        
        // Add a sentinel value to the end for easier boundary management
        occurrences.push_back(INT_MAX);
        
        int prev = occurrences[0], next = prev, idx = 1;
        
        // Iterate over the string and compute the minimum distance to the nearest occurrence of c
        for(int i = 0; i < n; ++i)
        {
            result[i] = min(abs(i - prev), abs(next - i));
            
            // Update the `prev` and `next` pointers when passing an occurrence of c
            if(i == next)
            {
                prev = next;
                next = occurrences[idx++];
            }
        }
        
        return result;
    }
};
