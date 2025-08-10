/*
 * Key Insight:
 * - Any permutation of n's digits that forms a power of two will have the same
 *   "canonical" digit pattern (digits sorted in ascending order).
 * - Example:
 *     n = 128 → "128" → sort → "128"
 *     2^7 = 128 → sort → "128" ✅ match
 *
 * Approach:
 * 1. Precompute canonical (sorted-digit) forms of all powers of two up to 2^29
 *    since 2^30 = 1073741824 (still fits in int).
 * 2. Store these canonical strings in a hash set for O(1) lookup.
 * 3. Sort the digits of n and check if it's in the set.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

class Solution {
public:
    bool reorderedPowerOf2(int n) 
    {
        int power = 1;
        unordered_set<string> canonicalPowerOf2;

        // Include the first power of 2: 2^0 = 1
        canonicalPowerOf2.insert("1");

        // Precompute sorted-digit representations of powers of 2
        for(int i = 0 ; i < 29 ; ++i)
        {
            power *= 2;
            string canonical = to_string(power);
            sort(canonical.begin(), canonical.end());
            canonicalPowerOf2.insert(canonical);
        }
        
        // Canonical form of input number
        string input = to_string(n);
        sort(input.begin(), input.end());

        // Check if input matches any power of 2's canonical form
        return canonicalPowerOf2.count(input);
    }
};