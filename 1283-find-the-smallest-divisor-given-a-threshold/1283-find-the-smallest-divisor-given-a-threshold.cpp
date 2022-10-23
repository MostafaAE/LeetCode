class Solution {
public:
    /* 
    * Approach:
    * binary search the smallest possible divisor
    * 
    * Complexity:
    * Time Complexity : O(nlogm) where m is the maximum element in the array
    * Space Complexity : O(1)
    */
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int start = 1, end = *max_element(nums.begin(), nums.end()), answer{end};

        while(start <= end)
        {
            int mid = start + (end - start)/2;
            
            if(possibleDivisor(nums, mid, threshold))
                end = mid - 1, answer = mid;
            else
                start = mid + 1;
        }
        
        return answer;
    }
    
    bool possibleDivisor(vector<int>& nums, int d, int threshold)
    {
        long long sum{};
        
        for(int elem : nums)
            sum += (elem + d-1)/d;
        
        return sum <= threshold;
    }
};