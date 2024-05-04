class Solution {
public:
    /*
    * Approach:
    * - Sort the people array, and use a two-pointer approach to find the optimal pairings of people in boats.
    * - For each boat, start with the heaviest person and try to pick the lightest person if possible.
    *
    * Complexity:
    * - Time Complexity: O(n logn), where n is the number of people.
    * - Space Complexity: O(1)
    */
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(people.begin(), people.end());
        
        int left{}, right = people.size() - 1, boatsCount{};
        
        while (left <= right) 
        {
            ++boatsCount;
            
            // Pick the heaviest person
            --right;
            
            // Pick the lightest person if possible
            if (left <= right && people[right+1] + people[left] <= limit) 
                ++left;
        }
        
        return boatsCount;
    }
};
