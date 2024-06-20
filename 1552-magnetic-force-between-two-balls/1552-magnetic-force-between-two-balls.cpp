class Solution {
public:
    /*
    * Approach:
    * - Sort the positions of the balls.
    * - Use binary search to find the largest minimum distance between the balls.
    * - The search range for the distance is between 1 and the maximum possible distance (difference between the smallest and largest position divided by m-1).
    * - For each midpoint distance, check if it's possible to place all m balls such that the minimum distance between any two balls is at least the midpoint distance.
    * 
    * Complexity:
    * - Time Complexity: O(n log(n*d))
    *   - Sorting the positions takes O(n log n).
    *   - Binary search runs in O(log d) iterations, where d is the difference between the smallest and largest position.
    *   - The isPossibleDistance check runs in O(n) for each iteration of binary search.
    * - Space Complexity: O(logn), for sorting.
    */
    int maxDistance(vector<int>& position, int m) 
    {
        int n = position.size();
        
        // Sort the positions of the stalls
        sort(position.begin(), position.end());
        
        // Binary search boundaries
        int start = 1; // Minimum possible distance
        int end = (position[n - 1] - position[0]) / (m - 1); // Maximum possible distance
        int result = 0;
        
        // Binary search to find the largest minimum distance
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            
            // Check if it's possible to place all balls with at least mid distance apart
            if(isPossibleDistance(position, m, mid))
            {
                result = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        
        return result;
    }
    
    // Helper function to check if it is possible to place m balls with at least 'distance' apart
    bool isPossibleDistance(vector<int>& position, int m, int distance)
    {
        int lastPosition = position[0], ballsPlaced = 1;
        
        for(int i = 1; i < position.size(); ++i)
        {
            if(position[i] - lastPosition >= distance)
            {
                lastPosition = position[i];
                ballsPlaced++;
                
                if(ballsPlaced == m)
                    return true;
            }
        }
        
        return false;
    }
};
