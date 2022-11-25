typedef long long ll;
class Solution {
public:
    /* 
    * Approach:
    * Evaluat postfix expression using stack
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    int evalRPN(vector<string>& tokens) 
    {
        stack<ll> values;
        
        for(int i = 0 ; i < (int)tokens.size() ; i++)
        {
            if((int)tokens[i].size() == 1 && !isdigit(tokens[i][0]))
            {
                ll b = values.top();  values.pop();
                ll a = values.top();  values.pop();
                values.push(eval(a, b, tokens[i][0]));
            }
            else
                values.push(stoll(tokens[i]));
        }
        return values.top();
    }
    
    ll eval(ll a, ll b, char op)
    {
        if(op == '+')
            return a + b;
        else if(op == '-')
            return a - b;
        else if(op == '*')
            return a * b;
        else
            return a / b;
    }
};