class Solution {
public:
    /**
     * Approach:
     * - The goal is to determine if the given rectangles divide the plane into at least 3 separate sections
     *   along either the x-axis or y-axis.
     * - We store the **start and end coordinates** of all rectangles for both x and y axes.
     * - **Sort** the coordinate pairs to process them in order.
     * - **Merge overlapping intervals** to count distinct sections.
     * - If **either axis has at least 3 sections**, return `true`.
     *
     * Complexity Analysis:
     * - **Overall Time Complexity**: **O(N log N)**
     *      - **Sorting** takes **O(N log N)** for each axis.
     *      - **Merging intervals** takes **O(N)**.
     * - **Space Complexity**: **O(N)** (for storing coordinate intervals).
     */
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) 
    {
        vector<pair<int, int>> xCoordinates, yCoordinates;

        // Step 1: Extract start and end coordinates for both axes
        for (auto& rect : rectangles)
        {
            int startX = rect[0], startY = rect[1], endX = rect[2], endY = rect[3];
            xCoordinates.emplace_back(startX, endX);
            yCoordinates.emplace_back(startY, endY);
        }

        // Step 2: Sort coordinates to facilitate merging intervals
        sort(xCoordinates.begin(), xCoordinates.end());
        sort(yCoordinates.begin(), yCoordinates.end());

        // Step 3: Count distinct sections along X and Y axes
        if (countSections(xCoordinates) >= 3)
            return true;

        return countSections(yCoordinates) >= 3;
    }

private:
    /**
     * Counts the number of distinct sections in a given sorted list of intervals.
     * Merges overlapping intervals and tracks separate sections.
     */
    int countSections(vector<pair<int, int>>& coordinates)
    {
        int end = -1, sections = 0;
        
        for (auto& coordinate : coordinates)
        {
            int curStart = coordinate.first, curEnd = coordinate.second;

            if (curStart < end) // Overlapping or touching intervals
            {
                end = max(end, curEnd);
            }
            else // New distinct section found
            {
                end = curEnd;
                ++sections;
            }
        }

        return sections;
    }
};