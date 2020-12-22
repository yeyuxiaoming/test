/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> res;
        bool flag = true;
        while(!que.empty()) {
            int n = que.size();
            deque<int> lev;
            while(n--) {
                TreeNode* cur = que.front();
                que.pop();
                if(!cur) {
                    continue;
                }
                if(flag) {
                    lev.push_back(cur->val);
                }
                else
                {
                    lev.push_front(cur->val);
                }
                que.push(cur->left);
                que.push(cur->right);
            }
            flag = !flag;
            
            if(lev.size() != 0) {
                //res.push_back(vector<int>{lev.begin(), lev.end()});
                res.emplace_back(vector<int>{lev.begin(), lev.end()});
            }
        }
        return res;
    }
};