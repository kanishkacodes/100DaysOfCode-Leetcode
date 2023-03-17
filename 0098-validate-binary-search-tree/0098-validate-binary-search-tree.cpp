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
    bool isValidBST(TreeNode* root, long min = LONG_MIN, long max = LONG_MAX){ 
       if(root == NULL)
           return true;
       if((root->val >= max) || (root->val <= min))
           return false;
       else
           return isValidBST(root->left,min,root->val) &&  isValidBST(root->right,root->val,max);
   }
 };