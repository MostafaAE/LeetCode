class Solution {
public:
    /*
    * Approach:
    * - Use a counting sort to sort the heights.
    * - Count the occurrences of each height and store them in a frequency map.
    * - Reconstruct the sorted heights using the frequency map.
    * - Compare the original heights with the sorted heights to determine how many heights are out of place.
    *
    * Complexity:
    * - Time Complexity: O(n + k), where n is the number of elements in the heights array and k is the maximum height value.
    * - Space Complexity: O(n)
    */
    int heightChecker(vector<int>& heights) 
    {
        int minVal = *min_element(heights.begin(), heights.end());
        int maxVal = *max_element(heights.begin(), heights.end());
        
        unordered_map<int, int> freq;
        vector<int> orderedHeights;
        
        // Count ther occurrence of each height
        for(auto height : heights)
            freq[height]++;
        
        // Sort the heights
        for(int i = minVal ; i <= maxVal ; ++i)
            while(freq[i]--)
                orderedHeights.push_back(i);
        
        // Compare the expected heights with the actual
        int count{};
        for(int i = 0 ; i < heights.size() ; ++i)
            if(heights[i] != orderedHeights[i])
                ++count;
        
        return count;
    }
};