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
    void print(struct TreeNode *root);
    struct TreeNode *deleteTreeLeaves(struct TreeNode *root);
};
Solution::Solution(){}
void Solution::print(struct TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    vector<int> res;
    stack<struct TreeNode *> s;
    s.push(root);
    while(!s.empty())
    {
        struct TreeNode *node = s.top();
        s.pop();
        res.push_back(node->val);
        if(node->right)
        {
            s.push(node->right);
        }
        if(node->left)
        {
            s.push(node->left);
        }
    }
    for(vector<int>::iterator iter = res.begin(); iter != res.end(); iter++)
    {
        cout << *iter<< " ";
    }
}
struct TreeNode *Solution::deleteTreeLeaves(struct TreeNode *root)
{
   if(root == NULL)
   {
       return NULL;
   }
   if(root->left == NULL && root->right == NULL)
   {
       free(root);
       return NULL;
   }
   root->left = deleteTreeLeaves(root->left);
   root->right = deleteTreeLeaves(root->right);
   return root;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;

    TreeNode *a = new TreeNode(1);
    a->left = new TreeNode(3);
    a->right = new TreeNode(2);
    a->left->left = new TreeNode(7);
    a->left->right = new TreeNode(6);
    a->right->left = new TreeNode(5);
    a->right->right = new TreeNode(4);
    a->left->left->right = new TreeNode(10);
    a->right->left->left = new TreeNode(9);
    a->right->left->right = new TreeNode(8);
    sol.print(a);
    cout <<endl;
    struct TreeNode *c = sol.deleteTreeLeaves(a);
    sol.print(c);
    return 0;
}
