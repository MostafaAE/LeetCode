class Solution {
public:
    /**
     * Approach:
     * 1. Use a max-heap to prioritize the class that benefits the most from adding an extra student. 
     *    The benefit is defined as the increase in pass ratio: 
     *    `(pass + 1) / (total + 1) - pass / total`.
     * 2. Push all classes into the heap, storing the potential increase in ratio and the class index.
     * 3. While extra students are available:
     *    - Pop the top class from the heap.
     *    - Update its `pass` and `total` values by adding one student.
     *    - Recalculate its benefit and push it back into the heap.
     * 4. Calculate the final average pass ratio by summing the pass ratios of all classes.
     * 
     * Complexity:
     * Time Complexity: O((n + k) * log n)
     * - O(n log n) to push all classes into the heap initially.
     * - O(k log n) for `k` extra students, as heap operations are O(log n).
     * Space Complexity: O(n)
     * - Space for the heap storing up to `n` classes.
     */
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) 
    {
        auto benefit = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };
        
        // Max-heap: stores {benefit, index}
        priority_queue<pair<double, int>> maxHeap;
        double result = 0.0;
        int n = classes.size();
        
        for (int idx = 0; idx < n; ++idx) 
        {
            int pass = classes[idx][0], total = classes[idx][1];
            
            double curRatio = (double)pass / total;
            
            maxHeap.push({benefit(pass, total), idx});
            
            result += curRatio;
        }
        
        while (extraStudents--) 
        {
            auto [gain, idx] = maxHeap.top();
            maxHeap.pop();
            
            int& pass = classes[idx][0];
            int& total = classes[idx][1];
            
            result += gain;
            ++pass;
            ++total;
            
            // Recalculate the new benefit and push back into the heap
            maxHeap.push({benefit(pass, total), idx});
        }
        
        return result / n;
    }
};
