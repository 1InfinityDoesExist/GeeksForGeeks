/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


// Returns maximum value in a given Binary Tree
int findMax(struct node* root)
{
// Your code goes here

    vector<vector<int> > res;
    map<int, vector<int> > mp;
    queue<pair<struct node *, int> >q;
    q.push(make_pair(root, 0));
    while(!q.empty())
    {
        pair<struct node *, int> p = q.front();
        q.pop();
        struct node *temp = p.first;
        int hd = p.second;

        mp[hd].push_back(temp->data);
        if(temp->left != NULL)
        {
            q.push(make_pair(temp->left, hd-1));
        }
        if(temp->right != NULL)
        {
            q.push(make_pair(temp->right, hd+1));
        }
    }

    for(map<int ,vector<int>>::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        res.push_back(iter->second);
    }
    vector<int> ans;
    for(int iter = 0; iter < res.size(); iter++)
    {
        for(int jter = 0; jter < res[iter].size(); jter++)
        {
            ans.push_back(res[iter][jter]);
        }
    }
    vector<int>::iterator iter = max_element(ans.begin(), ans.end());
    return *iter;
}
// Returns minimum value in a given Binary Tree
int findMin(struct node* root)
{
// Your code goes here

    vector<vector<int> > res;
    map<int, vector<int> > mp;
    queue<pair<struct node *, int> >q;
    q.push(make_pair(root, 0));
    while(!q.empty())
    {
        pair<struct node *, int> p = q.front();
        q.pop();
        struct node *temp = p.first;
        int hd = p.second;

        mp[hd].push_back(temp->data);
        if(temp->left != NULL)
        {
            q.push(make_pair(temp->left, hd-1));
        }
        if(temp->right != NULL)
        {
            q.push(make_pair(temp->right, hd+1));
        }
    }

    for(map<int ,vector<int>>::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        res.push_back(iter->second);
    }
    vector<int> ans;
    for(int iter = 0; iter < res.size(); iter++)
    {
        for(int jter = 0; jter < res[iter].size(); jter++)
        {
            ans.push_back(res[iter][jter]);
        }
    }
    vector<int>::iterator iter = min_element(ans.begin(), ans.end());
    return *iter;
}
