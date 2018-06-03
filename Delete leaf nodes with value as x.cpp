#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int data):val(data),left(NULL),right(NULL){}
};
class Solution
{
private:
public:
    Solution();
    void printTree(struct TreeNode *root);
    struct TreeNode *deleteLeaf(struct TreeNode *root, const int x);
};
Solution::Solution(){}
struct TreeNode *Solution::deleteLeaf(struct TreeNode *root, const int x)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL && root->val == x)
    {
        free(root);
        return NULL;
    }
    root->left = deleteLeaf(root->left, x);
    root->right = deleteLeaf(root->right, x);
    return root;
}
void Solution::printTree(struct TreeNode *root)
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
        cout << *iter << "  ";
    }
    cout << endl;
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
    int x = 10;
    sol.printTree(a);
    struct TreeNode *del = sol.deleteLeaf(a, x);
    sol.printTree(del);
    return 0;
}
