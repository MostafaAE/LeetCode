class Solution {
public:

    long long eval(long long operand1, long long operand2, string operation)
    {
        if(operation == "+")
            return operand1 + operand2;
        else if(operation == "-")
            return operand1 - operand2;
        else if(operation == "*")
            return operand1 * operand2;
        else
            return operand1 / operand2;
    }

    int evalRPN(vector<string>& tokens) 
    {
        stack<long long> operands;
        for(string t : tokens)
        {
            if(isdigit(t[0]) || t.size() > 1)
                operands.push(stoi(t));
            else
            {
                long long operand2 = operands.top(); operands.pop();
                long long operand1 = operands.top(); operands.pop();
                long long result = eval(operand1, operand2, t);
                operands.push(result);
            }
        }
        return operands.top();
    }
};