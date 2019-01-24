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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> map;
        vector<TreeNode*> res;
        DFS(root, map, res);
        return res;
    }
    string DFS(TreeNode* root, unordered_map<string, int> &map, vector<TreeNode*> &res) {
        if (!root) {
            return "";
        }
        string s = to_string(root->val) + "," + DFS(root->left, map, res) + "," + DFS(root->right, map, res);
        cout << s << " " << map[s] << endl;
        if (map[s]++ == 1) {
            cout << map[s] << endl;
            res.push_back(root);
        }
        return s;
    }
};

/*
给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

两棵树重复是指它们具有相同的结构以及相同的结点值。

深度优先遍历，先把叶子节点放到 s 中，向上放入父节点的时候查看 map 中是否有重复的即为重复子树
*/