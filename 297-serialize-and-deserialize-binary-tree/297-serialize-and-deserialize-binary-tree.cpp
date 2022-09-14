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
    
    int idx = 0;
    TreeNode *des(vector<string> &nodes)
    {
        if (nodes[idx] == "x")
        {
            idx++;
            return nullptr;
        }
        TreeNode *node = new TreeNode(stoi(nodes[idx]));
        idx++;
        node->left = des(nodes);
        node->right = des(nodes);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        vector<string> nodes = split(data, ',');

        return des(nodes);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));