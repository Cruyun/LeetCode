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
    bool isBalanced(TreeNode* root) {
        return depth(root) == -1 ? false : true;
    }
    
    int depth(TreeNode* root) {
       if (root == NULL)
           return 0;
        
        int h1 = depth(root->left);
        if (h1 == -1)
            return -1;

        int h2 = depth(root->right);
        if (h2 == -1)
            return -1;
        
        int diff = abs(h1 - h2);
        
        if (diff > 1) 
            return -1;
        else
            return 1 + max(h1, h2);
    }
};