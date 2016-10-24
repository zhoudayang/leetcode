//思路：dfs,分为两种情况：从根节点开始，包括根节点；从子节点开始，递归调用。
class Solution {
public:
    int pathSum(TreeNode *root, int sum) {
        if (root == nullptr)
            return 0;
        return helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int helper(TreeNode *root, int sum) {
        if (root == nullptr)
            return 0;
        int result = 0;
        if (sum == root->val)
            ++result;
        result += helper(root->left, sum - root->val) + helper(root->right, sum - root->val);
        return result;
    }
};

