class Solution {
public:
    int scoreOfParentheses(string s)
    {
        stack<int> parser;
        parser.push(0);

        for (char c : s)
        {
            if (c == '(')
                parser.push(0);
            else
            {
                int last = parser.top();
                parser.pop();

                if (last == 0)
                    last = 1;
                else
                    last *= 2;

                int parentVal = parser.top() + last;
                parser.pop();
                parser.push(parentVal);
            }
        }
        return parser.top();
    }
};