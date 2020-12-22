/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 ����һ����������������ڵ�ֵ�ľ���β�������������ȴ������ң��ٴ������������һ��������Դ����ƣ������֮�佻����У���
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