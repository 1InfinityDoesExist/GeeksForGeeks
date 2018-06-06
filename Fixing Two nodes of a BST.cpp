
void bst(struct node *root, vector<int> &A)
{
    if(root == NULL || A.size() == 0)
    {
        return;
    }
    bst(root->left, A);
    root->data = A.front();
    A.erase(A.begin());
    bst(root->right, A);
}
struct node *correctBST(struct node* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    vector<int> ans;
    stack<struct node *> s;
    struct node *ptr = root;
    while(!s.empty() || ptr)
    {
        if(ptr)
        {
            s.push(ptr);
            ptr = ptr->left;
        }
        else
        {
           struct node *node = s.top();
           s.pop();
           ans.push_back(node->data);
           ptr = node->right;
        }
    }
    sort(ans.begin(), ans.end());
    bst(root, ans);
    return root;

}
