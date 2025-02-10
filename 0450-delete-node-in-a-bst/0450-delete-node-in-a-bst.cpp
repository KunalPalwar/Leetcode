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
   
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;

        if(root->val == key){
            if(root->left == nullptr && root->right == nullptr) return nullptr;

            TreeNode* left = root->left;
            if(left == nullptr){
                return root->right;
            }

            TreeNode* parent = left;
            TreeNode* current = left->right;

            while(left->right){
                current = left->right;
                parent = left;
                left = left->right;
            }

            if(current == nullptr) {
                left->right = root->right;
                return root->left;
            }
            root->val = current->val;
            parent->right = nullptr;

            return root;




        }else if(root->val > key){
            root->left =  deleteNode(root->left,key);
            return root;
        }else{
            root->right =  deleteNode(root->right,key);
            return root;
        }
        
    }
};