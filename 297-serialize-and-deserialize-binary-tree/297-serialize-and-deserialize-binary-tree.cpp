/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    //split string at certain delimeter
    vector<string> split(const string &s, char delim)
    {
        vector<string> result;
        stringstream ss(s);
        string item;

        while (getline(ss, item, delim))
        {
            result.push_back(item);
        }

        return result;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if (!root)
            return "x,";

        string ser;

        ser += to_string(root->val) + ",";
        ser += serialize(root->left);
        ser += serialize(root->right);

        return ser;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        vector<string> nodes = split(data, ',');

        if (nodes[0] == "x")
            return nullptr;

        stack<TreeNode *> st;
        TreeNode *root = new TreeNode(stoi(nodes[0]));

        st.push(root);
        bool left = 1;
        for (int i = 1; i < (int)nodes.size(); i++)
        {
            if (nodes[i] == "x")
            {
                if (left)
                {
                    st.top()->left = nullptr;
                    left = 0;
                }

                else
                {
                    st.top()->right = nullptr;
                    st.pop();
                }
            }
            else
            {
                TreeNode *cur = new TreeNode(stoi(nodes[i]));
                if (left)
                {
                    st.top()->left = cur;
                }
                else
                {
                    st.top()->right = cur;
                    st.pop();
                }

                st.push(cur);

                left = 1;
            }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));