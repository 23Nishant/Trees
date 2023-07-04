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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> level;
        if( !root ){
            return ans;
        }
        level.push(root);
        int cnt = 1;
        while( !level.empty() ){
            int n = level.size();
            vector<int> temp;
            
            for( int i = 0; i < n; i++ ){
                TreeNode* x = level.front();
                if(x->left){
                    level.push(x->left);
                }
                if( x->right ){
                    level.push(x->right);
                }
                temp.push_back(x->val);
                level.pop();
            }
            if( cnt % 2 == 0 ){
                reverse(temp.begin(),temp.end());
            }
            cnt++;
            ans.push_back(temp);
        }

        return ans;

    }
};
