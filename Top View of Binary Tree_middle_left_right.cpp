
void topView(struct Node *root)
{
    // Your code here
    if(root == NULL)
    {
        return;
    }
    vector<vector<int> > res;
    queue<pair<struct Node *, int>  > q;
    set<int> st;
    st.insert(0);
    q.push(make_pair(root, 0));
    cout << root->data << " ";
    while(!q.empty())
    {
        pair<struct Node *, int>  temp = q.front();
        q.pop();
        int hd = temp.second;
        struct Node *node = temp.first;

        if(node->left)
        {
            q.push(make_pair(node->left, hd-1));
            if(st.find(hd-1) == st.end())
            {
                cout << node->left->data<<" ";
                st.insert(hd-1);
            }
        }
        if(node->right)
        {
            q.push(make_pair(node->right, hd+1));
            if(st.find(hd+1) == st.end())
            {
                cout << node->right->data << " ";
                st.insert(hd+1);
            }
        }
    }
    return;
}
