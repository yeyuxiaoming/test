/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*988:给定一颗根结点为?root?的二叉树，树中的每一个结点都有一个从?0 到?25?的值，分别代表字母?'a' 到?'z'：值?0 代表?'a'，值?1?代表?'b'，依此类推。找出按字典序最小的字符串，该字符串从这棵树的一个叶结点开始，到根结点结束。（小贴士：字符串中任何较短的前缀在字典序上都是较小的：例如，在字典序上?"ab" 比?"aba"?要小。叶结点是指没有子结点的结点。）
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
