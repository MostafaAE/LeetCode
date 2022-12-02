class Solution {
public:
    /* 
    * Approach:
    * For each query, sort the element in range (l, r) and check if s[i+1] - s[i] == s[1] - s[0] for all valid i
    * 
    * Complexity:
    * Time Complexity : O(m*nlogn)
    * Space Complexity : O(n)
    */
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        int m{(int)l.size()};
        vector<bool> answer(m, 1);
        
        for(int i = 0 ; i < m ; i++)
        {
            vector<int> cpy(nums.begin()+l[i], nums.begin()+r[i]+1);
            
            // O(nlogn)
            sort(cpy.begin(), cpy.end());
            
            int diff = cpy[1] - cpy[0];
            for(int j = 2 ; j < (int)cpy.size() ; j++)
            {
                if(cpy[j]-cpy[j-1] != diff)
                {
                    answer[i] = 0;
                    break;
                }
            }
        }
        
        return answer;
    }
};