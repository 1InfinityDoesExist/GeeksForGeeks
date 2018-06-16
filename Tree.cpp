//https://www.youtube.com/watch?v=McOvhN_jH5k

#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int data) : val(data), left(NULL), right(NULL){}
};
class Solution{
private:
public:
    Solution();
    void preOrderTraversal(struct TreeNode *root);
    void inOrderTraversal(struct TreeNode *root);
    void postOrderTraversal(struct TreeNode *root);
    void verticalOrderTraversal(struct TreeNode *root);
    void verticalWithRootFirst(struct TreeNode *root);
    int heightOfTreeRecursion(struct TreeNode *root);//Height of tree recursion..
    int heightIterative(struct TreeNode *root);//height of tree iterative method...
};
Solution::Solution(){}
int Solution::heightIterative(struct TreeNode *root)
{
    if(root == NULL)
    {
        return 0;
    }
    queue<struct TreeNode *> q;
    q.push(root);
    int h = 0;
    while(1)
    {
        int iter = q.size();
        if(iter == 0)
        {
            return h;
        }
        h++;
        while(iter--)
        {
            struct TreeNode *node = q.front();
            q.pop();
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
    }
}
int Solution::heightOfTreeRecursion(struct TreeNode *root)
{
    if(root == NULL)
    {
        return 0;
    }
    int l = heightOfTreeRecursion(root->left);
    int r = heightOfTreeRecursion(root->right);
    if(l > r)
    {
        return l+1;
    }
    else
    {
        return r+1;
    }
}
void Solution::verticalWithRootFirst(struct TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    set<int> s;
    queue<pair<struct TreeNode *, int> > q;
    cout << root->val << " ";
    q.push(make_pair(root, 0));
    s.insert(0);
    while(!q.empty())
    {
        pair<struct TreeNode *, int>  p = q.front();
        q.pop();
        struct TreeNode *node = p.first;
        int hd = p.second;

        if(node->left)
        {
            q.push(make_pair(node->left, hd-1));
            if(s.find(hd-1) == s.end())
            {
                cout << node->left->val << " ";
                s.insert(hd-1);
            }

        }
        if(node->right)
        {
            q.push(make_pair(node->right, hd+1));
            if(s.find(hd+1) == s.end())
            {
                cout << node->right->val << " ";
                s.insert(hd+1);
            }
        }
    }
    cout << endl;
    return;
}
void Solution::verticalOrderTraversal(struct TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    map<int, vector<int> > mp;
    queue<pair<struct TreeNode *, int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty())
    {
        pair<struct TreeNode *, int > p = q.front();
        q.pop();
        struct TreeNode *node = p.first;
        int hd = p.second;
        mp[hd].push_back(node->val);
        if(node->left)
        {
            q.push(make_pair(node->left, hd-1));
        }
        if(node->right)
        {
            q.push(make_pair(node->right, hd+1));
        }
    }
    vector<vector<int> > ans;
    for(map<int, vector<int> >::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        ans.push_back(iter->second);
    }

    cout << "Printing for Vertical Order Traversal of BSTree"<<endl;
    for(int iter = 0; iter < ans.size(); iter++)
    {
        for(int jter = 0; jter < ans[iter].size(); jter++)
        {
            cout << ans[iter][jter] << " ";
        }
        cout << endl;
    }
}
void Solution::postOrderTraversal(struct TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    vector<int> ans;
    stack<struct TreeNode *> s;
    stack<struct TreeNode *> output;
    s.push(root);
    while(!s.empty())
    {
        struct TreeNode *node = s.top();
        s.pop();
        output.push(node);
        if(node->left)
        {
            s.push(node->left);
        }
        if(node->right)
        {
            s.push(node->right);
        }
    }
    while(!output.empty())
    {
        ans.push_back(output.top()->val);
        output.pop();
    }
    for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    return;
}
void Solution::inOrderTraversal(struct TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    vector<int> ans;
    stack<struct TreeNode *> st;
    struct TreeNode *ptr = root;
    while(!st.empty() || ptr)
    {
        if(ptr)
        {
            st.push(ptr);
            ptr = ptr->left;
        }
        else
        {
            struct TreeNode *node = st.top();
            st.pop();
            ans.push_back(node->val);
            ptr = node->right;
        }
    }
    for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    return;
}
void Solution::preOrderTraversal(struct TreeNode *root)
{

    if(root == NULL)
    {
        return;
    }
    vector<int> ans;
    stack<struct TreeNode *> st;
    st.push(root);
    while(!st.empty())
    {
        struct TreeNode *node = st.top();
        st.pop();
        ans.push_back(node->val);
        if(node->right)
        {
            st.push(node->right);
        }
        if(node->left)
        {
            st.push(node->left);
        }
    }
    for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout <<endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    struct TreeNode *root = new TreeNode(1);
    root->left            = new TreeNode(2);
    root->right           = new TreeNode(3);
    root->left->left      = new TreeNode(4);
    root->left->right     = new TreeNode(5);
    sol.preOrderTraversal(root);
    sol.inOrderTraversal(root);
    sol.postOrderTraversal(root);
    sol.verticalOrderTraversal(root);
    sol.verticalWithRootFirst(root);

    int heightRecursion = sol.heightOfTreeRecursion(root);
    cout << "Height Of Tree is --->" << heightRecursion << endl;
    int heightIterative = sol.heightIterative(root);
    cout <<"Height of Tree using iterative process is--> "<< heightIterative << endl;
    return 0;
}
