class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1) >> neglecting the output space
    */
    vector<string> fizzBuzz(int n) 
    {
        vector<string> result;
        
        for(int i = 1 ; i <= n ; i++)
        {
            string val{};
            if(i%3 == 0)
                val = "Fizz";
            if(i%5 == 0)
                val += "Buzz";
            if(val.empty())
                val += to_string(i);
            
            result.push_back(val);
        }
        return result;
    }
};