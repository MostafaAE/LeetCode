class Solution {
public:
    /* 
    * Approach:
    * Iterate on the array two times, while using a stack to find the next greater element for every element 
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n{(int)nums.size()};
        vector<int> answer(n, -1);
        stack<int> st;
        
        for(int i = 0 ; i < 2 ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                while(!st.empty() && nums[st.top()] < nums[j])
                    answer[st.top()] = nums[j], st.pop();
                
                if(!i)
                    st.push(j);
            }
        }
        return answer;
    }
};