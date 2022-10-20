class Solution {
public:
    /* 
    * Approach:
    * sort the array, then find the minimum absolute difference across the array
    * push each pair with the minimum abs diff in the result
    * 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(1) >> neglecting the output space
    */
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        vector<vector<int>> result;
        int minAbsDif{INT_MAX};

        // O(nlogn)
        sort(arr.begin(), arr.end());

        // find the minimum absolute difference
        // O(n)
        for (int i = 1; i < (int)arr.size(); i++)
            minAbsDif = min(arr[i] - arr[i - 1], minAbsDif);

        // push each pair with the minimum abs diff in the result
        // O(n)
        for (int i = 1; i < (int)arr.size(); i++)
            if (arr[i] - arr[i - 1] == minAbsDif)
                result.push_back({arr[i - 1], arr[i]});

        return result;
    }
};