/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return NULL;
        }
        insert(root, val);
        return root;
    }
    void insert(TreeNode* root, int val) {
        if (root->val < val) {
            if (root->right) {
                insert(root->right, val);
            } else {
                root->right = new TreeNode(val);
            }
        } else {
            if (root->left) {
                insert(root->left, val);
            } else {
                root->left = new TreeNode(val);
            }
        }
        return;
    }
};