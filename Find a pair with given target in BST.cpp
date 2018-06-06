
bool isPairPresent(struct node *root, int target)
{
//add code here.
    if(root == NULL)
    {
        return true;
    }
    vector<int> ans;
    queue<struct node *> q;
    q.push(root);
    while(!q.empty())
    {
        struct node *node = q.front();
        q.pop();
        ans.push_back(node->val);
        if(node->left)
        {
            q.push(node->left);
        }
        if(node->right)
        {
            q.push(node->right);
        }
    }
    sort(ans.begin(), ans.end());
   int start = 0;
   int end = ans.size()-1;
   while(start < end)
   {
       if(ans[start]+ans[end] == target)
       {
           return true;
       }
       else if(ans[start] + ans[end] < target)
       {
           start++;
       }
       else
       {
           end--;
       }
   }
    return false;
}
