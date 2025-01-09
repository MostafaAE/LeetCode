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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> list1, list2;
        inorder(root1, list1);
        inorder(root2, list2);

        return mergeLists(list1, list2);
    }

    void inorder(TreeNode* node, vector<int>& vals)
    {
        if(node == nullptr)
            return;
        
        inorder(node->left, vals);
        vals.push_back(node->val);
        inorder(node->right, vals);
    }

    vector<int> mergeLists(vector<int>& list1, vector<int>& list2)
    {
        int len1 = list1.size(), len2 = list2.size(), itr1{}, itr2{};
        vector<int> result;

        while(itr1 < len1 || itr2 < len2)
        {
            if(itr1 < len1 && itr2 < len2)
            {
                if(list1[itr1] < list2[itr2])
                    result.push_back(list1[itr1++]);
                else
                    result.push_back(list2[itr2++]);
            }
            else if(itr1 < len1)
                result.push_back(list1[itr1++]);
            else if(itr2 < len2)
                result.push_back(list2[itr2++]);
        }

        return result;
    }
};