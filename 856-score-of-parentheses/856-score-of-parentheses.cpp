class Solution {
public:
    int scoreOfParentheses(string s)
    {
        int result = 0;
        stack<int> parser;

        for (char c : s)
        {
            if (c == '(')
                parser.push(0);
            else
            {
                int val = 0;
                while (!parser.empty() && parser.top() != 0)
                    val += parser.top(), parser.pop();
                parser.pop();
                val ? parser.push(val * 2) : parser.push(1);
            }
        }
        while (!parser.empty())
            result += parser.top(), parser.pop();

        return result;
    }
};