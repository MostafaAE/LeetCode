class Solution {
public:
    /* 
    * Approach:
    * prefix sum
    * 
    * Complexity:
    * Time Complexity : O(n^2)
    * Space Complexity : O(1)
    */
    int sumOddLengthSubarrays(vector<int>& arr) 
    {
        prefixSum(arr);
        int sum{};
        for(int i = 0 ; i < (int)arr.size() ; i++)
        {
            for(int j = i ; j < (int)arr.size() ; j+=2)
            {
                sum += arr[j];
                if(i > 0)
                    sum -= arr[i-1];
            }
        }
        return sum;
    }
    
    void prefixSum(vector<int>& arr)
    {
        for(int i = 1; i < (int)arr.size() ; i++)
            arr[i] += arr[i-1];
    }
};