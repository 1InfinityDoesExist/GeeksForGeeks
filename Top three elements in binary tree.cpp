#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int data) : val(data),left(NULL), right(NULL){}
};
class Solution
{
private:
public:
    Solution();
    vector<int> topThreeElements(struct TreeNode *root);
};
Solution::Solution(){}
vector<int> Solution::topThreeElements(struct TreeNode *root)
{
    vector<int> res;
    if(root == NULL)
    {
        return res;
    }
    vector<int> temp;
    queue<struct TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        struct TreeNode *node = q.front();
        q.pop();
        temp.push_back(node->val);
        if(node->left)
        {
            q.push(node->left);
        }
        if(node->right)
        {
            q.push(node->right);
        }
    }
    sort(temp.begin(), temp.end(), greater<int>());
    if(temp.size() >= 3)
    {
        res.push_back(temp[0]);
        res.push_back(temp[1]);
        res.push_back(temp[2]);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    struct TreeNode *a = new TreeNode(1);
    a->left = new TreeNode(3);
    a->right = new TreeNode(2);
    a->left->left = new TreeNode(7);
    a->left->right = new TreeNode(6);
    a->right->left = new TreeNode(5);
    a->right->right = new TreeNode(4);
    a->left->left->right = new TreeNode(10);
    a->right->left->left = new TreeNode(9);
    a->right->left->right = new TreeNode(8);
    vector<int> ans = sol.topThreeElements(a);
    for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
    {
        cout << *iter << " ";
    }
    return 0;
}
