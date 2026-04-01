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
    int depth ( TreeNode * temp){
        if (temp==nullptr )return 0 ;

        else return 1 + max ( depth(temp->left) , depth(temp->right)) ;

        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0 ;
        int dia = depth(root->left ) + depth( root->right)  ;
        if (dia> max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)))
            return dia ; 
        else return max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
    }
};
