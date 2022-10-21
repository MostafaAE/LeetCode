class Solution {
public:
    /* 
    * Approach:
    * calculate the arrival time of each monster by dividing dist / speed
    * count the number of monsters that we can eliminate
    * 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(n)
    */
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) 
    {
        int size = (int)dist.size();
        int cnt {1};
        vector<int> time(size);
        
        for(int i = 0 ; i < size ; i++)
            time[i] = ceil((double)dist[i] / speed[i]);
        
        sort(time.begin(), time.end());
        
        if(time[0] == 0)
            return cnt;
        
        for(int i = 1 ; i < size ; i++)
        {
            // lose condition
            if(time[i] - cnt == 0)
                return cnt;
            
            cnt++;
        }
        
        return cnt;
    }
};