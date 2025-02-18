class Solution {
public:
    string smallestNumber(string pattern) 
    {
        string result;
        stack<int> numStack;

        // Iterate through the pattern
        for (int index = 0; index <= pattern.size(); index++) 
        {
            // Push the next number onto the stack
            numStack.push(index + 1);

            // If 'I' is encountered or we reach the end, pop all stack elements
            if (index == pattern.size() || pattern[index] == 'I')
            {
                while (!numStack.empty()) 
                {
                    result += to_string(numStack.top());
                    numStack.pop();
                }
            }
        }

        return result;
    }
};