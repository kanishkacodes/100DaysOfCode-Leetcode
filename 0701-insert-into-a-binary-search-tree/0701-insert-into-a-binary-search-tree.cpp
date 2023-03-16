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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
TreeNode * ins=new TreeNode(val);
if(root==NULL)
{
    return ins;
}

TreeNode* tmp=root;


while(1)
{
     if(tmp->val >val)
     {
         if(tmp->left)
         {tmp=tmp->left;}
         else
         {
             tmp->left=ins;
             return root;
         }
     }
     else if(tmp->val <val)
     {

         if(tmp->right)
        { tmp=tmp->right;}
         else
         {
             tmp->right=ins;
             return root;
         }

     }

     
}
return root;
        
    }
};