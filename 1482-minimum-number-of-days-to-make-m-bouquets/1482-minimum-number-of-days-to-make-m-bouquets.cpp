class Solution {
public:
    /* 
    * Approach:
    * binary search the minimum number of days
    * 
    * Complexity:
    * Time Complexity : O(nlogm) where m is the maximum element in the array
    * Space Complexity : O(1)
    */
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        if(m > (int)bloomDay.size() / k)
            return -1;
        
        int start = 1, end = *max_element(bloomDay.begin(), bloomDay.end()), answer {end};
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            
            if(possibleDay(bloomDay, m, k , mid))
                end = mid - 1, answer = mid;
            else
                start = mid + 1;
        }
        
        return answer;
    }
    
    bool possibleDay(vector<int>& bloomDay, int m, int k, int day)
    {
        int cnt{};
        for(int i = 0 ; i < (int)bloomDay.size() ; i++)
        {
            if(bloomDay[i] <= day)
                cnt++;
            else
                cnt = 0;
            
            if(cnt == k)
            {
                cnt = 0;
                --m;
                
                // return early
                if(m == 0)
                    return true;
                
            }
        }
        return m <= 0;
    }
};