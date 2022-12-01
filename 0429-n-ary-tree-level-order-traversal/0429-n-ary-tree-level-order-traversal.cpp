/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    /* 
    * Approach: 
    * Breadth-First Search
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> result;
        if(!root)
            return result;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> level;
            
            while(sz--)
            {
                Node* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                
                for(Node* child : cur->children)
                    q.push(child);
            }
            result.push_back(level);;
        }
        
        return result;
    }
};