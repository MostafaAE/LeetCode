class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int left = 1, right = 1000000, result{};

        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(isValid(nums, mid, threshold))
            {
                result = mid;
                right = mid - 1;
                
            }
            else
                left = mid + 1;
        }

        return result;
    }

    bool isValid(vector<int>& nums, int divisor, int threshold)
    {
        int divSum{};

        for(int num : nums)
            divSum += ceil(num / (double)divisor);
            
        return divSum <= threshold;
    }
};