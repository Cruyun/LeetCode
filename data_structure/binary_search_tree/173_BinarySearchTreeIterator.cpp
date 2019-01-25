/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> s;
    void searchLeft(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        searchLeft(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* t = s.top();
        s.pop();
        TreeNode* node = t->right;
        searchLeft(node);
        return t->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */