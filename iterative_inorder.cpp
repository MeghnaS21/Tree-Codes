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
    vector<int> inorderTraversal(TreeNode* root) {
        //create a answer vector
        vector<int>inorder;
        //create a stack of type treenode pointer
        stack<TreeNode*> st;
        //create a temp node for traversal, so that we do not lose the root/head
        TreeNode* tempNode = root;
        //traverse through the left and put every node simultaneously in the stack
        //once null encounterered, change the pointer to right
        //and do it till the stack is not empyt

        while(true){
            //traverse till you encounter null
            if(tempNode != NULL){
                st.push(tempNode);
                tempNode = tempNode->left;
            }
            else{
                if(st.empty()==true) break;
                tempNode = st.top();
                st.pop();
                inorder.push_back(tempNode->val);
                tempNode=tempNode->right;
            }

        }
        return inorder;
    }
};
