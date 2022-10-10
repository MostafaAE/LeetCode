/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<int> nextGreaterElement(vector<int>& preorder)
    {
        stack<int> st;
        vector<int> result((int)preorder.size());
        st.push(0);
        for(int i = 1 ; i < (int)preorder.size() ;i++)
        {
            while(!st.empty() && preorder[i] > preorder[st.top()])
            {
                result[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            result[st.top()] = (int)preorder.size();
            st.pop();
        }
        return result;
    }
        
    // O(n) solution
    TreeNode* bstFromPreorder(vector<int>& preorder, vector<int>& nextGreater, int start, int end) 
    {
        if(start > end)
            return nullptr;
        
        TreeNode *curRoot = new TreeNode(preorder[start]);
        
        int nextGreaterIdx = nextGreater[start];
        if(nextGreaterIdx > end)
            nextGreaterIdx = end +1;
            
        curRoot->left = bstFromPreorder(preorder,nextGreater, start+1, nextGreaterIdx-1);
        curRoot->right = bstFromPreorder(preorder,nextGreater, nextGreaterIdx, end);
        
        return curRoot;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        vector<int> nextGreater = nextGreaterElement(preorder);
        return bstFromPreorder(preorder,nextGreater,  0, (int)preorder.size()-1);
        
    }
};