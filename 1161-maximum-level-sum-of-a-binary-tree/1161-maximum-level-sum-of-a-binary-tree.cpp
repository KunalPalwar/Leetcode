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
    int maxLevelSum(TreeNode* root) {
        if(root == nullptr) return 0;

        int answer = 1;
        int maxima = INT_MIN;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int temp = 0;
            for(int i=0;i<size;i++){
                TreeNode* current = q.front();
                q.pop();
                temp+=current->val;

                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            level++;
            if(temp > maxima){
                answer = level;
                maxima = temp;
            }
        }

        return answer;
        
    }
};