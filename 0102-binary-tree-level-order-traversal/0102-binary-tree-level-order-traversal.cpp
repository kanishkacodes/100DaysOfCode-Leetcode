/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode * root ,vector<vector<int>>&ans,int d=0){
      if(!root)return;
      if(d>=ans.size())ans.push_back({});
      ans[d].push_back(root->val);
      dfs(root->left,ans,d+1);
      dfs(root->right,ans,d+1);
  }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
         if(!root)return ans;
         dfs(root,ans);
        return ans;
    }
};