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
    int ans = 0;
    pair<int, int> Helper(TreeNode* root){
        if(root == nullptr){
            return {0, 0};
        }

        int cnt = 0;
        int sum = 0;
        // sum, cnt
        pair<int, int> arr1 = Helper(root->left);
        pair<int, int> arr2 = Helper(root->right);

        sum = (arr1.first + arr2.first + root->val);
        cnt = (arr1.second + arr2.second + 1);
        if(root->val == sum/cnt){
            ans++;
        }

        return {sum, cnt};

    }

    int averageOfSubtree(TreeNode* root) {
        pair<int, int> arr = Helper(root);

        return ans;
    }   
};