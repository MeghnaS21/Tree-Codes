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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //to store the answer
        vector<vector<int>> ans;
        //base
        if(root==NULL) return ans;

        queue<TreeNode*> tracker;
        tracker.push(root);

        while(!tracker.empty()){
            int size = tracker.size(); //1
            vector<int> level; //for storing answer level wise
            for(int i=0;i<size;i++){
                TreeNode* current_node = tracker.front();
                tracker.pop();
                if(current_node->left != NULL) tracker.push(current_node->left);
                if(current_node->right != NULL ) tracker.push(current_node->right);
                level.push_back(current_node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
