/*
 * Approach:
 * The goal is to maximize the number of players who can be matched with trainers.
 * A player can be matched with a trainer only if the trainer's strength is ≥ player's requirement.
 * 
 * Strategy:
 * - Sort both `players` and `trainers` in ascending order.
 * - Use a two-pointer approach:
 *     - Traverse both arrays, and whenever a player can be matched with a trainer (trainer ≥ player),
 *       increase the match count and move to the next player and trainer.
 *     - Otherwise, move only to the next trainer (since current trainer is too weak).
 * 
 * Time Complexity  : O(n log n + m log m), where n = players.size() and m = trainers.size()
 *                    - Sorting takes O(n log n + m log m)
 *                    - Linear scan takes O(n + m)
 *
 * Space Complexity : O(log n + log m) for sorting
 */

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) 
    {
        int n = players.size(), m = trainers.size();

        // Sort both arrays to allow greedy matching
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int matched = 0;
        int playerIdx = 0, trainerIdx = 0;

        // Two-pointer approach to match players to trainers
        while (playerIdx < n && trainerIdx < m)
        {
            if (players[playerIdx] <= trainers[trainerIdx])
            {
                ++matched;
                ++playerIdx;
            }

            ++trainerIdx;
        }

        return matched;
    }
};