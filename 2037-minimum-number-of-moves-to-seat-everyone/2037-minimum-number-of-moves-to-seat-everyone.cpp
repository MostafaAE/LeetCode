class Solution {
public:
    /* 
    * Approach: 
    * - Sort both seats and students positions in ascending order using count sort.
    * - Greedily match each student to the nearest seat to him.
    *
    * Complexity:
    * - Time Complexity : O(n + m)
    * - Space Complexity : O(m)
    */
    int minMovesToSeat(vector<int>& seats, vector<int>& students) 
    {
        int n = seats.size(), minMoves{};
        
        countSort(seats);
        countSort(students);
        
        for(int i = 0 ; i < n ; ++i)
            minMoves += abs(seats[i] - students[i]);
        
        return minMoves;
    }
    
    void countSort(vector<int>& nums)
    {
        int maxVal = *max_element(nums.begin(), nums.end());
        
        vector<int> freq(maxVal+1, 0);
        
        for(auto val : nums)
            freq[val]++;
        
        for(int i = 1, idx = 0 ; i <= maxVal ; ++i)
            while(freq[i]--)
                nums[idx++] = i;
    }
};