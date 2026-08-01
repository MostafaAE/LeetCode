class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int n = bloomDay.size();

        if(m > n / k)
            return -1;

        int left = 1, right = 1e9, result = -1;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(isValid(bloomDay, m, k, mid))
            {
                right = mid - 1;
                result = mid;
            }
            else
                left = mid + 1;
        }

        return result;
    }

    bool isValid(vector<int>& bloomDay, int m, int k, int days)
    {
        int bouquets = 0, n = bloomDay.size(), i = 0;
        while(i <= n-k && bouquets < m)
        {
            int cnt = 0;
            for(int j = 0 ; j < k ; ++j)
            {
                if(bloomDay[i+j] > days)
                    break;
                ++cnt;
            }

            if(cnt == k)
            {
                ++bouquets;
                i += k;
            }
            else
                ++i;
        }

        return bouquets >= m;
    }
};