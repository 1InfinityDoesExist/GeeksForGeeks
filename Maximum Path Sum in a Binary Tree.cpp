#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int data) : val(data), left(NULL), right(NULL){}
};
class Solution
{
private:
public:
    Solution();
    int maxFinder(struct TreeNode *root);
    int helper(struct TreeNode *root, int &sum);
};
Solution::Solution(){}
int Solution::helper(struct TreeNode *root, int &sum)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftNode = helper(root->left, sum);
    int rightNode = helper(root->right, sum);

    int a = max(max(leftNode, rightNode) + root->val, root->val);
    int b = max(a, leftNode + rightNode + root->val);

    sum = max(sum, b);
    return a;
}
int Solution::maxFinder(struct TreeNode *root)
{
    if(root == NULL)
    {
        return 0;
    }
    int sum = INT_MIN;
    helper(root, sum);
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    int ans = sol.maxFinder(root);
    cout << ans <<endl;
    return 0;
}
