class Solution {
public:
    /**
     * Approach:
     * 1. Use an unordered set `targets` to store numbers from the array while iterating.
     * 2. For each element in the array:
     *    - Check if twice the current number (`arr[i] * 2`) exists in `targets`.
     *    - If the current number is even, check if half of it (`arr[i] / 2`) exists in `targets`.
     *    - If either condition is true, return `true`.
     *    - Otherwise, add the current number to `targets`.
     * 3. If the loop completes without finding a match, return `false`.
     * 
     * Complexity:
     * Time Complexity: O(n)
     * - Each element is processed once, and set operations (insert, count) are O(1) on average.
     * Space Complexity: O(n)
     * - Space for the `targets` set, which can grow up to the size of the input array.
     */
    bool checkIfExist(vector<int>& arr) 
    {
        unordered_set<int> targets;

        for (int i = 0; i < arr.size(); ++i)
        {
            // Check for twice or half of the current element
            if (targets.count(arr[i] * 2) || (!(arr[i] & 1) && targets.count(arr[i] / 2)))
                return true;

            // Insert the current element into the set
            targets.insert(arr[i]);
        }

        return false;
    }
};
