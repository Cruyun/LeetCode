/**
 * 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* createTree(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir) {
        if (il > ir || pl > pr) {
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[pl]);
        for (int k = il; k <= ir; k++) {
            if (inorder[k] == preorder[pl]) {
                node->left = createTree(preorder, pl + 1, pl + k - il, inorder, il, k - 1);
                node->right = createTree(preorder, pl + k - il + 1, pr, inorder, k + 1, ir);
            }
        }
        return node;
    }
};