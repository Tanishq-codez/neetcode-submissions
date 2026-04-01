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
    void invert(TreeNode* root){
        TreeNode *temp = root ;
        if (temp == nullptr){
            return  ; 
        }
        invert (temp->left);
        invert (temp->right);

        TreeNode *temp2 = temp->left ;
        temp-> left = temp->right ;
        temp-> right = temp2 ; 
    }
    TreeNode* invertTree(TreeNode* root) {
       
       invert (root);

       return root ; 


       }
};
