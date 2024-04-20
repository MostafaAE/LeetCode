class Solution {
public:
    /* 
    * Approach:
    * To maximize the equation yi + yj + |xi - xj|, we can rewrite it as yi + yj + (xj - xi) since xj > xi for all values.
    * We can use a priority queue to store for each point i, the pair [yi-xi, xi].
    * This way, the highest [yi-xi] will always give us the highest value for the equation.
    * We iterate through each point, and for each point, we:
    *   1. Pop elements from the priority queue if the distance between the current point's xi and the top element's xi exceeds k.
    *   2. Calculate the equation value for the current point and update the maximum value accordingly.
    *   3. Push the current point's [yi-xi, xi] pair onto the priority queue.
    *
    * Complexity:
    * Time Complexity: O(nlogn)
    * Space Complexity: O(n)
    */
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) 
    {
        // Max heap to store pairs [yi-xi, xi].
        priority_queue<pair<int, int>> maxHeap; 
        int maxVal{INT_MIN};
        
        for(auto& point : points)
        {
            // Pop elements from the priority queue if the distance between the current point's xi and the top element's xi exceeds k.
            while(!maxHeap.empty() && point[0] - maxHeap.top().second > k)
                maxHeap.pop();
            
            if(!maxHeap.empty())
                // Calculate the equation value for the current point and update the maximum value accordingly.
                maxVal = max(maxVal, point[1] + point[0] + maxHeap.top().first);
            
            // Push the current point's [yi-xi, xi] pair onto the priority queue.
            maxHeap.push({point[1] - point[0], point[0]});
        }
        
        return maxVal;
    }
};
