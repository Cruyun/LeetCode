/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        TreeLinkNode *cur = root->next;
		TreeLinkNode *pre = NULL;
        while (cur != NULL) {
            if (cur->left != NULL) {
                pre = cur->left;
                break;
            }
            if (cur->right != NULL) {
                pre = cur->right;
                break;
            }
            cur = cur->next;
        }
        if (root->right != NULL) {
            root->right->next = pre;
        }
        if (root->left != NULL) {
            root->left->next = root->right == NULL ? pre : root->right;
        }
        connect(root->right);
        connect(root->left);
    }
};