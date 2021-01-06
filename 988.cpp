/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*988:����һ�Ÿ����Ϊ?root?�Ķ����������е�ÿһ����㶼��һ����?0 ��?25?��ֵ���ֱ������ĸ?'a' ��?'z'��ֵ?0 ����?'a'��ֵ?1?����?'b'���������ơ��ҳ����ֵ�����С���ַ��������ַ������������һ��Ҷ��㿪ʼ����������������С��ʿ���ַ������κν϶̵�ǰ׺���ֵ����϶��ǽ�С�ģ����磬���ֵ�����?"ab" ��?"aba"?ҪС��Ҷ�����ָû���ӽ��Ľ�㡣��
*/
class Solution{
public:
    string ans = "z";
    void reverse(string& s){
        int len = s.size()-1;
        int mid = len/2;
        int i = 0;
        while(i<=mid){
            char temp = s[i];
            s[i] = s[len-i];
            s[len-i] = temp;
            i++;
        }
    }

    void DFS(TreeNode* root, string s){
        s += char('a' + root->val);
        if(root->left == NULL && root->right == NULL){
            reverse(s);
            if(s < ans) ans = s;
        }
        if(root->left) DFS(root->left, s);
        if(root->right) DFS(root->right, s);
    }

    string smallestFromLeaf(TreeNode* root) {
        if(root==NULL) return ans;
        //string str = "";
        DFS(root, "");
        return ans;
    }
};
