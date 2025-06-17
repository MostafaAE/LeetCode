class Solution {
public:
    /*
    * Approach:
    * - Sort the people array by height in decreasing order.
    * - If two people have the same height, sort them by increasing k (number of people in front).
    * - Iterate over the sorted array:
    *   - Insert each person at index equal to k in the result vector.
    *   - Since taller people are already placed, inserting at k ensures correctness.
    *
    * Time Complexity: O(n^2)
    *
    * Space Complexity: O(1) ignoring output space.
    */
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        int n = people.size();

        // Sort people by decreasing height.
        // For equal height, sort by increasing k.
        sort(people.begin(), people.end(), [](const auto& a, const auto& b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
        });

        vector<vector<int>> result;

        // Insert each person at index = k
        for (auto& p : people)
        {
            result.insert(result.begin() + p[1], p);
        }

        return result;
    }
};