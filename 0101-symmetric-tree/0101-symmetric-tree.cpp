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
 //bfs 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true; 

        queue<TreeNode*> q; 
        q.push(root->left);
        q.push(root->right); 

        while(!q.empty()){
            TreeNode* t1 = q.front(); 
            q.pop(); 
            TreeNode* t2 = q.front();
            q.pop(); 

            //둘다비어있으면 대칭
            if (!t1 && !t2) continue; 
            //대칭 깨짐
            if (!t1 || !t2 || t1->val != t2->val) return false; 

            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }


        return true; 
    }
};