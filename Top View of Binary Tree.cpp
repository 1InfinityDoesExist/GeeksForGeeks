
void topView(struct Node *root)
{
    // Your code here
    if(root == NULL)
    {
        return;
    }
    vector<vector<int> > res;
    queue<pair<struct Node *, int>  > q;
    map<int, vector<int> > mp;
    q.push(make_pair(root, 0));
    while(!q.empty())
    {
        pair<struct Node *, int>  temp = q.front();
        q.pop();
        int hd = temp.second;
        struct Node *node = temp.first;

        mp[hd].push_back(node->data);
        if(node->left)
        {
            q.push(make_pair(node->left, hd-1));
        }
        if(node->right)
        {
            q.push(make_pair(node->right, hd+1));
        }
    }

    for(map<int, vector<int> >::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        res.push_back(iter->second);
    }
    for(int iter = 0; iter < res.size(); iter++)
    {
        cout << res[iter][0] << " ";
    }
}
