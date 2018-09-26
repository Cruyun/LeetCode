/**
 * 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return symmetricHelper(root->left, root->right);
    }
    bool symmetricHelper(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) {
            return true;
        }
        if (left == NULL || right == NULL) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        return symmetricHelper(left->left, right->right) && symmetricHelper(left->right, right->left);
    }
};