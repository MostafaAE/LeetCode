class Solution {
public:
    /**
     * Approach:
     * - Use a map to associate heights with names, sorting by height automatically since map keys are sorted.
     * - Traverse the map in reverse order to get names in descending order of heights.
     * - Push each name into the result vector.
     *
     * Complexity:
     * - Time Complexity: O(n logn) where n is the number of people
     * - Space Complexity: O(n)
     */
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        int n = names.size();
        
        map<int, string> heightToName;
        vector<string> result;
        
        for(int i = 0 ; i < n ; ++i)
            heightToName[heights[i]] = names[i];
        
        auto itr = heightToName.rbegin();
        
        while(itr != heightToName.rend())
        {
            result.push_back(itr->second);
            ++itr;
        }
        
        return result;
    }
};