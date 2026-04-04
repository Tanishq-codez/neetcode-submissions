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
    void solve ( TreeNode *root , int &gn , int maxi){
    if ( root == nullptr ) return ;

    if ( root->val >= maxi ){
        maxi = root->val ; 
        gn++ ; 
    }

    solve ( root->left , gn  , maxi );
    solve(root->right , gn , maxi );
    
    }
    int goodNodes(TreeNode* root) {
       int gn = 1 ; 
       
       int maxi = root->val ;

       solve ( root->left , gn  , maxi );
       solve(root->right , gn , maxi );

       return gn ; 
       
    }
};
