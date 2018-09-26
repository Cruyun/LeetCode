/**
 * 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return createTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* createTree(vector<int>& inorder, int il, int ir, vector<int>& postorder, int pl, int pr) {
        if (il > ir || pl > pr) {
            return NULL;
        }
        TreeNode* node = new TreeNode(postorder[pr]);
        for (int k = il; k <= ir; k++) {
            if (inorder[k] == postorder[pr]) {
                node->left = createTree(inorder, il, k - 1, postorder, pl, pl + k - il - 1);
                node->right = createTree(inorder, k + 1, ir, postorder, pl + k - il, pr - 1);
            }
        }
        return node;
    }
};