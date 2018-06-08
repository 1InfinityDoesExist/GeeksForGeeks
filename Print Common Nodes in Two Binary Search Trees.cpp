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
    vector<int> commonElements(struct TreeNode *root1, struct TreeNode *root2);
    vector<int> treeElements(struct TreeNode *root);
};
Solution::Solution(){}
vector<int> Solution::treeElements(struct TreeNode *root)
{
    vector<int> res;
    if(root == NULL)
    {
        return res;
    }
    stack<struct TreeNode *> s;
    struct TreeNode *ptr = root;
    while(!s.empty() || ptr)
    {
        if(ptr)
        {
            s.push(ptr);
            ptr = ptr->left;
        }
        else
        {
            struct TreeNode *node = s.top();
            s.pop();
            res.push_back(node->val);
            ptr = node->right;
        }
    }
    return res;
}
vector<int> Solution::commonElements(struct TreeNode *root1, struct TreeNode *root2)
{
    vector<int> ans;
    vector<int> r1 = treeElements(root1);
    vector<int> r2 = treeElements(root2);

    r1.erase(unique(r1.begin(), r1.end()), r1.end());
    r2.erase(unique(r2.begin(), r2.end()), r2.end());

    map<int, int> mp;
    for(vector<int>::iterator iter = r1.begin(); iter != r1.end(); iter++)
    {
        mp[*iter]++;
    }
    for(vector<int>::iterator iter = r2.begin(); iter != r2.end(); iter++)
    {
        mp[*iter]++;
        if(mp[*iter] == 2)
        {
            ans.push_back(*iter);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    struct TreeNode *a = new struct TreeNode(1);
    a->left = new TreeNode(3);
    a->right = new TreeNode(2);
    a->left->left = new TreeNode(7);
    a->left->right = new TreeNode(6);
    a->right->left = new TreeNode(5);
    a->right->right = new TreeNode(4);
    a->left->left->right = new TreeNode(10);
    a->right->left->left = new TreeNode(9);
    a->right->left->right = new TreeNode(8);


    struct TreeNode *b = new struct TreeNode(1);
    b->left = new TreeNode(3);
    b->right = new TreeNode(101);
    b->left->left = new TreeNode(74);
    b->left->right = new TreeNode(6);
    b->right->left = new TreeNode(7);
    b->right->right = new TreeNode(4);
    b->left->left->right = new TreeNode(10);
    b->right->left->left = new TreeNode(91);
    b->right->left->right = new TreeNode(8);

    vector<int> ans = sol.commonElements(a, b);
    for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}
