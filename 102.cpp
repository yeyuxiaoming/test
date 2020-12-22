/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 102:����һ�������������㷵���䰴 ������� �õ��Ľڵ�ֵ�� �������أ������ҷ������нڵ�
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