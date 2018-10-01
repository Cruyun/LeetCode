/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "[]";
        }
        string res = "[";
        queue<TreeNode*> Queue;
        Queue.push(root);
        char str[100];
        while (!Queue.empty()) {
            TreeNode* node = Queue.front();
            Queue.pop();
            if (node != NULL) {
                Queue.push(node->left);
                Queue.push(node->right);
                sprintf(str, "%d", node->val);
                res += str;
            } else {
                res = res + "null";
            }
            res += ",";
        }
        
        int end = res.length() - 1;
        while ( !( res[end] >= '0' && res[end] <= '9') ) {
            end--;
        }
        
        string ans = res.substr(0, end + 1) + "]";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() <= 2) {
            return NULL;
        }
        vector<TreeNode*> tree;
        string word = "";
        for (int i = 1; i < data.length() - 1; i++) {
            if (data[i] == ',') {
                TreeNode* node = NULL;
                if (word != "null") {
                    int num = atoi(word.c_str());
                    node = new TreeNode(num);
                }
                tree.push_back(node);
                word = "";
            } else {
                word += data[i];
            }
        }
        // last word
        if (word != "" && word != "null") {
            int num = atoi(word.c_str());
            TreeNode* node = new TreeNode(num);
            tree.push_back(node);
        }
        int cnt = tree.size();

        int q = 0;
        int p = 1;
        while (p < cnt) {
            if (tree[q] == NULL){
                q++;
            } else {
                if (p < cnt) {
                    tree[q]->left = tree[p];
                }    
                if (p + 1 < cnt) {
                    tree[q]->right = tree[p + 1];
                }
                p += 2;
                q++;
            }
        }
        return tree[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));