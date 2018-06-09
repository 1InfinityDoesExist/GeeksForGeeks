/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/* Should print vertical order such that each vertical line
   is separated by $ */
void verticalOrder(Node *root)
{
    //Your code here
    map<int, vector<int> > mp;
    stack<pair<struct Node *, int > > q;
    q.push(make_pair(root, 0));
    while(!q.empty())
    {
        pair<struct Node *, int> p = q.top();
        q.pop();
        struct Node *node = p.first;

        int hd = p.second;
        mp[hd].push_back(node->data);
        if(node->right)
        {
            q.push(make_pair(node->right, hd+1));
        }
        if(node->left)
        {
            q.push(make_pair(node->left, hd-1));
        }
    }
    vector<vector<int> > res;
    for(map<int, vector<int> >::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        res.push_back(iter->second);
    }
    for(int iter = 0; iter < res.size(); iter++)
    {
        for(int jter = 0; jter < res[iter].size(); jter++)
        {
            cout << res[iter][jter] << " ";
        }
        cout << '$';
    }
}
