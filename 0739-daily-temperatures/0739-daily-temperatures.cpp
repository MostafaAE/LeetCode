class Solution {
public:
    /* 
    * Approach:
    * Use stack to find the next greater element
    * 
    * Complexity:
    * Time Complexity : O(n) => iterating on elements ~twice only
    * Space Complexity : O(n)
    */
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n{(int)temperatures.size()};
        vector<int> answer(n, 0);
        stack<int> temps;
        
        for(int i = 0 ; i < n ; i++)
        {
            while(!temps.empty() && temperatures[i] > temperatures[temps.top()])
                answer[temps.top()] = i - temps.top(), temps.pop();
            
            temps.push(i);
        }

        return answer;        
    }
};