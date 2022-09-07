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
    string tree2str(TreeNode* root) {
        string l, r;
        if(root->left != NULL)
            l = "(" + tree2str(root->left) + ")";
        else
            l = root->right == NULL ? "" : "()";
        if(root->right != NULL)
            r = "(" + tree2str(root->right) + ")";
        else
            r = "";
        return to_string(root->val) + l + r;
    }
};
