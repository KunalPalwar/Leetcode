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
    void Helper(TreeNode* root,int &count,int maxSoFar){
        if(root == nullptr) return;
        
        if(root->val >= maxSoFar){
            maxSoFar = root->val;
            count++;
        }
        Helper(root->left,count,maxSoFar);
        Helper(root->right,count,maxSoFar);
        
    }
    int goodNodes(TreeNode* root) {
        
        if(root == nullptr) return 0;
        int count = 0;
        int maxSoFar = INT_MIN;
        Helper(root,count,maxSoFar);
        
        return count;
        
    }
};