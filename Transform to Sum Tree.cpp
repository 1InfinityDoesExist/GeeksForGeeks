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
        void preorder(struct TreeNode *root);
        int sumTree(struct TreeNode *root);
 };
 Solution::Solution(){}
 int Solution::sumTree(struct TreeNode *root)
 {
     if(root == NULL)
     {
         return 0;
     }
     int old_val = root->val;
     root->val = sumTree(root->left) + sumTree(root->right);
     return old_val + root->val;
 }
 void Solution::preorder(struct TreeNode *root)
 {
     vector<int> res;
     if(root == NULL)
     {
         return;
     }
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
     cout << endl;
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
    int ans = sol.sumTree(a);
    cout << ans <<endl;

    return 0;
}
