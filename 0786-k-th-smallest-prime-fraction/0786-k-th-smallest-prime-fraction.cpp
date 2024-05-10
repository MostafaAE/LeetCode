class Solution {
public:
    /* 
    * Approach: 
    * - Priority Queue approach (The smallest fractions will be formed by dividing each element by the largest element in the array).
    * - Initialize a priority queue that stores pairs in the form {-fraction, {numerator_index, denominator_index}}.
    * - Start by pushing all possible fractions formed by dividing each element by the last element of the array into the priority queue.
    * - Iteratively remove the top element from the priority queue and replace it with a new fraction formed by dividing the same numerator by the next smaller denominator.
    * - Essentially, we replace the smallest fraction with the next smallest fraction having the same numerator. Repeating this k - 1 times leaves the kth smallest fraction at the top of the priority queue.
    *
    * Complexity:
    * - Time Complexity : O((n+k) logn)
    * - Space Complexity : O(n)
    */
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) 
    {
        int n = arr.size();
        priority_queue<pair<double, pair<int, int>>> pq;
        
        for(int i = 0 ; i < n - 1 ; ++i)
        {
            double fraction = (double)arr[i] / arr[n-1];
            pq.push({-fraction, {i, n-1}});
        }
        
        while(--k)
        {
            auto [numeratorIdx, denominatorIdx] = pq.top().second;
            pq.pop();
            double fraction = (double)arr[numeratorIdx] / arr[denominatorIdx - 1];
            pq.push({-fraction, {numeratorIdx, denominatorIdx-1}});
        }
    
        auto [i, j] = pq.top().second;
        return {arr[i], arr[j]};
    }
};