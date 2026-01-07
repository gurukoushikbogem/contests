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
class Solution
{
public:
    vector<long long> ssum;
    long long mod = 1e9 + 7;
    long long sum(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        long long temp_sum = root->val + sum(root->left) + sum(root->right);
        ssum.push_back(temp_sum);
        return temp_sum;
    }
    int maxProduct(TreeNode *root)
    {
        long long tsum = sum(root);
        long long ans = 0;
        for (int s : ssum)
        {
            ans = max(ans, (tsum - s) * s);
        }
        return ans % mod;
    }
};