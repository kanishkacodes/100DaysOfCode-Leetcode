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
    unordered_map<int,int> mp ;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size() , i ;
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i ;
        }
        TreeNode *ans = solve(inorder,0,n-1,postorder,0,n-1) ;
        return ans ;
    }
    TreeNode* solve(vector<int>& inorder,int is,int ie,vector<int>& postorder,int ps,int pe){
        if(is>ie || ps>pe){
            return NULL ;
        }
        TreeNode* root =  new TreeNode(postorder[pe]) ;
        int root_ind = mp[postorder[pe]] ;
        int numLeft = root_ind - is ;
        root->left = solve(inorder,is,root_ind-1,postorder,ps,ps+numLeft-1) ;
        
        root->right = solve(inorder,root_ind+1,ie,postorder,ps+numLeft,pe-1) ;

        return root ;
    }
};