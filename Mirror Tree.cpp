#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

 class Solution
 {
     private:
     public:
        Solution();
        int mirror_image(struct TreeNode *A);
        void preorder(struct TreeNode *root);
 };
 Solution::Solution(){}
 void Solution::preorder(struct TreeNode *root)
 {
     vector<int> res;
     stack<struct TreeNode *> s;
     s.push(root);
     while(!s.empty())
     {
         struct TreeNode *temp = s.top();
         s.pop();
         res.push_back(temp->val);
        if(temp->right)
         {
             s.push(temp->right);
         }
         if(temp->left)
         {
             s.push(temp->left);
         }

     }

     for(vector<int>::iterator iter = res.begin(); iter != res.end(); iter++)
     {
         cout << *iter << " ";
     }
 }
 int Solution::mirror_image(struct TreeNode *root)
 {
    if(root == NULL)
    {
        return 0;
    }
    stack<struct TreeNode *> s;
    s.push(root);
    while(!s.empty())
    {
        struct TreeNode *node = s.top();
        s.pop();
        if(node)
        {
            s.push(node->left);
            s.push(node->right);
            swap(node->left, node->right);
        }
    }
    return true;
 }

int main(int argc, char *argv)
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
    sol.preorder(a);
    cout << endl;
    int ans = sol.mirror_image(a);
    sol.preorder(a);
   // cout << ans <<endl;

    return 0;
}
