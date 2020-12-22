/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 102:给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> res;
        while(!que.empty()) {
            int n = que.size();
            vector<int> lev;
            while(n--) {
                TreeNode* cur = que.front();
                que.pop();
                if(!cur) {
                    continue;
                }
                lev.push_back(cur->val);
                que.push(cur->left);
                que.push(cur->right);
            }
            if(lev.size() != 0) {
                res.push_back(lev);
            }
        }
        return res;
    }
};