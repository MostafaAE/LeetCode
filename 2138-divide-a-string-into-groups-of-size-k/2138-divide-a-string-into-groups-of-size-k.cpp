/*
 * Approach:
 * - Group the string `s` into substrings of size `k`.
 * - If the last group is shorter than `k`, fill it with `fill` character.
 * - Use a simple loop and string append.
 * 
 * Time Complexity : O(max(n, k)), where n = size of s, k = group size.
 * Space Complexity: O(1), ignoring output space.
 */

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) 
    {
        int n = s.size();
        int groupsCount = (n + k - 1) / k;

        vector<string> result(groupsCount);
        
        for (int i = 0; i < n; ++i)
            result[i / k] += s[i];
        
        result[groupsCount - 1] += string(k - result[groupsCount - 1].size(), fill);

        return result;
    }
};
