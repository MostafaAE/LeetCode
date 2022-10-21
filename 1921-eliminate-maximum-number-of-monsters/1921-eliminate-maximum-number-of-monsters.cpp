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
        int killed {};
        vector<int> arrivalTime(size);
        
        for(int i = 0 ; i < size ; i++)
            arrivalTime[i] = ceil((double)dist[i] / speed[i]);
        
        sort(arrivalTime.begin(), arrivalTime.end());
        
        for(int i = 0 ; i < size && i < arrivalTime[i] ; i++)
            killed++;
        
        return killed;
    }
};