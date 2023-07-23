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
    unordered_map<int,vector<TreeNode*>>dp;
    vector<TreeNode*> build(int n)
    {
        vector<TreeNode*>nodes;
        if(n%2==0)
            return nodes;
        if(n==1)
        {
            TreeNode* node=new TreeNode(0);
            nodes.push_back(node);
            return nodes;
        }
        if(dp.find(n)!=dp.end())
            return dp[n];
        for(int i=1;i<n;i+=2)
        {
            vector<TreeNode*> left=build(i);
            vector<TreeNode*> right=build(n-i-1);
            for(auto l:left)
            {
                for(auto r:right)
                {
                    TreeNode* root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    nodes.push_back(root);
                }
            }  
        }
        return dp[n]= nodes;
    }
    vector<TreeNode*> allPossibleFBT(int n) 
    {
        return build(n);
    }
};