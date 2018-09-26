/**
 * 给定一个二叉树，返回其按层次遍历的节点值
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        deque<TreeNode *> Queue;
        TreeNode* head = root;
        Queue.push_back(head);
        int currentLevelNodeCount = 1;
        int nextLevelNodeCount = 0;
        int count = 0;
        vector<int> levelResult;
        while(!Queue.empty()) {
            head = Queue.front();
            Queue.pop_front();
            count++;
            levelResult.push_back(head->val);
            
            if (head->left != NULL) {
                Queue.push_back(head->left);
                nextLevelNodeCount++;
            }
            if (head->right != NULL) {
                Queue.push_back(head->right);
                nextLevelNodeCount++;
            }
            if (count == currentLevelNodeCount) {
                result.push_back(levelResult);
                levelResult.clear();
                count = 0;
                currentLevelNodeCount = nextLevelNodeCount;
                nextLevelNodeCount = 0;
            }
        }
        return result;
    }
};