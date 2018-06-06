long long int sum;

void solve(struct Node *root, long long int cur)
{
    cur = cur*10 + root->data;
    if(root->left == NULL && root->right == NULL)
    {
        sum = sum + cur;
    }
    if(root->left)
    {
        solve(root->left, cur);
    }
    if(root->right)
    {
        solve(root->right, cur);
    }
}
long long treePathsSum(Node *root)
{
    //Your code here
    if(root == NULL)
    {
        return 0;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    sum = 0;
    solve(root, 0);
    return sum;
}
