int sumLeaf(Node* root)
{
    // Code here
    if(root == NULL)
    {
        return 0;
    }
    queue<struct Node *> q;
    q.push(root);
    int leaf_sum (0);
    while(!q.empty())
    {
        struct Node *node = q.front();
        q.pop();
        if(node->left == NULL && node->right == NULL)
        {
            leaf_sum = leaf_sum + node->data;
        }
        if(node->left)
        {
            q.push(node->left);
        }
        if(node->right)
        {
            q.push(node->right);
        }
    }
    return leaf_sum;
}
