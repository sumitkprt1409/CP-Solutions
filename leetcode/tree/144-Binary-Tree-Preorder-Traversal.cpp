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
    void Preorder(TreeNode *root, vector<int> &arr){
        if(root == nullptr){
            return;
        }

        arr.push_back(root->val);
        Preorder(root->left, arr);
        Preorder(root->right, arr);

    }

    vector<int> PreOrder(TreeNode *root){
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode *ele = st.top();
            if(root == nullptr){
                return ans;
            }
            st.pop();
            ans.push_back(ele->val);
            if(ele->right != nullptr){
                st.push(ele->right);
            }
            if(ele->left != nullptr){
                st.push(ele->left);
            }
        }
        return ans;
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        // Preorder(root, arr);
        arr = PreOrder(root);
        return arr;

    }
};