/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //directed acyclic graph to undirected acyclic graph
    void buildGraph(TreeNode* root,unordered_map<int,vector<int>>& graph){
        
        if(root->left!=NULL){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            buildGraph(root->left,graph);
        }
        if(root->right!=NULL){            
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            buildGraph(root->right,graph);            
        }
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        if(K==0)
            return {target->val};
        
        //initialisation 
        
        unordered_map<int,vector<int>> graph; //graph
        unordered_map<int,bool> visited;
        vector<int> res;
        queue<int> q;
        int cnt = 0;
        
        //build the graph
        buildGraph(root,graph);
        
        //push the target to start bfs with
        q.push(target->val);
        
        //bfs
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                
                int curr = q.front();
                q.pop();
                visited[curr]=true;
                
                for(int x : graph[curr])
                    if(!visited[x])
                        q.push(x);
            }
            cnt++;
            //we reached the Kth layer, push the layer in res vector and break bfs
            if(cnt==K){
                while(!q.empty()){
                    res.push_back(q.front());
                    q.pop();
                }
                break;
            }
                
        }
        
        return res;
    }
};