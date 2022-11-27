/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    /* 
    * Approach:
    * Iterate over the tree using DFS checking if all the elements in the linked list starting from the head
    * correspond to some downward path in the binary tree.
    * 
    * Complexity:
    * Time Complexity: O(n * min(L,h)) where L is the list length and h is the tree height
    * Space Complexity: O(h) => auxiliary space for stack
    * h could be (n) or (logn) depending on the shape of the tree
    */
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        if(!head)
            return 1;
        if(!root)
            return 0;
        
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head,root->right);
    }
    
    bool dfs(ListNode* head, TreeNode* root)
    {
        if(!head)
            return 1;
        if(!root)
            return 0;

        return root->val == head->val && (dfs(head->next, root->left) || dfs(head->next, root->right));
    }
};