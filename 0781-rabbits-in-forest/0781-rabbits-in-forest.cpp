/**
 * Approach:
 * - Each element in the input array represents a rabbit's answer: 
 *   "There are 'x' other rabbits with the same color as me", 
 *   meaning there are (x + 1) rabbits of that color in total.
 * 
 * - We group rabbits with the same answer. For each group:
 *   - Let `answer = x` and `count = number of rabbits who said x`.
 *   - The maximum group size with the same color is (x + 1).
 *   - So we need ceil(count / (x + 1)) groups of size (x + 1).
 *   - Total rabbits = number of groups * group size.
 * 
 * Time Complexity: O(N), where N is the size of the input array.
 * Space Complexity: O(N), in the worst case, each rabbit gives a different answer.
 */

class Solution {
public:
    int numRabbits(vector<int>& answers) 
    {
        unordered_map<int, int> answerToCount;

        // Count how many times each answer appears
        for (int answer : answers)
        {
            ++answerToCount[answer];
        }

        int result = 0;

        // Calculate the minimum number of rabbits based on grouped answers
        for (auto [answer, count] : answerToCount)
        {
            int groupSize = answer + 1;

            // Calculate how many full groups are needed
            int groups = ceil((double)count / groupSize);

            // Total rabbits = number of groups * size of each group
            result += groups * groupSize;
        }

        return result;
    }
};
