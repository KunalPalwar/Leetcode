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
    void Helper(TreeNode* first,vector<int>&temp){
        if(first == nullptr) return;
        if(first->left == nullptr && first->right == nullptr){
            temp.push_back(first->val);
            return;
        }
        
        Helper(first->left,temp);
        Helper(first->right,temp);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>first,second;
        Helper(root1,first);
        Helper(root2,second);
        if(first.size() != second.size()) return false;
        
        for(int i=0;i<first.size();i++){
            if(first[i]!=second[i]) return false;
        }
        return true;
    }
};