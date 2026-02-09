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
    vector<int> arr;
    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        return balancedTree(0, arr.size() - 1);
    }
    void inOrder(TreeNode* root)
    {
        if(root == NULL)return;
        inOrder(root->left);
        arr.push_back(root->val);
        inOrder(root->right);
    }

    TreeNode* balancedTree(int l, int r)
    {
        if(l > r)return nullptr;
        int m = (l + r) >> 1;
        TreeNode* le = balancedTree(l, m - 1);
        TreeNode* ri = balancedTree(m + 1, r);
        return new TreeNode(arr[m], le, ri);
    }
};
