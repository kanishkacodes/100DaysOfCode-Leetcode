//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};




// } Driver Code Ends

class Solution {
public:
    // Helper method to check if the values in the subtree rooted at 'root'
    // are within the given range [min, max].
    bool rangeMethod(Node* root, int min, int max) {
        // If the current node is NULL, it is considered as a valid BST node.
        if (root == NULL) {
            return true;
        }
        
        // Check if the value of the current node is within the range.
        if (root->data >= min && root->data <= max) {
            // Recursively check the left and right subtrees.
            // For the left subtree, the maximum value should be the current node's value - 1.
            bool left = rangeMethod(root->left, min, root->data - 1);
            // For the right subtree, the minimum value should be the current node's value + 1.
            bool right = rangeMethod(root->right, root->data + 1, max);
            
            // Return true only if both left and right subtrees are valid BSTs.
            return left && right;
        }
        
        // If the value of the current node is not within the range, it is not a valid BST node.
        else {
            return false;
        }
    }
    
    // Function to check whether a Binary Tree is a BST or not.
    bool isBST(Node* root) {
        // Call the helper method with the initial range of minimum and maximum values.
        return rangeMethod(root, INT_MIN, INT_MAX);
    }
};




//{ Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
 
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
    string s; 
    getline(cin, s);
    Node* root = buildTree(s);
    Solution ob;
    if(ob.isBST(root)) 
        cout<<"1\n";
        
    else
        cout<<"0\n";
   }
   return 0;
}


// } Driver Code Ends