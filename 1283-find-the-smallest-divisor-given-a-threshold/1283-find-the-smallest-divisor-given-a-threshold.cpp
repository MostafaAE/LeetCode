class Solution {
public:
    /* 
    * Approach:
    * binary search the smallest possible divisor
    * 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(1)
    */
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int start = 1;
        int end = 1e6;
        int answer{};
        
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
    
    bool possibleDivisor(vector<int>& nums, double d, int threshold)
    {
        long long sum{};
        
        for(int elem : nums)
            sum += ceil(elem/d);
        
        return sum <= threshold;
    }
};