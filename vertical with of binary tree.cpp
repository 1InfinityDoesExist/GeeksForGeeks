#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int val): data(val), left(NULL), right(NULL){}
};
class Solution
{
private:
public:
    Solution();
    int verticalWidthOfBinaryTree(struct TreeNode *root);
};
Solution::Solution(){}
int Solution::verticalWidthOfBinaryTree(struct TreeNode * root)
{
    if(root == NULL)
    {
        return 0;
    }
    vector<int> ans;
    queue<pair<struct TreeNode *, int> > q;
    set<int> st;
    st.insert(0);
    ans.push_back(root->data);
    q.push(make_pair(root, 0));
    while(!q.empty())
    {
        pair<struct TreeNode *, int> temp = q.front();
        q.pop();
        int hd = temp.second;
        struct TreeNode *node = temp.first;
        if(node->left)
        {
            q.push(make_pair(node->left, hd-1));
            if(st.find(hd-1) == st.end())
            {
                ans.push_back(node->left->data);
                st.insert(hd-1);
            }
        }
        if(node->right)
        {
            q.push(make_pair(node->right, hd+1));
            if(st.find(hd+1) == st.end())
            {
                ans.push_back(node->right->data);
                st.insert(hd+1);
            }
        }
    }
    return ans.size();

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

    int ans = sol.verticalWidthOfBinaryTree(a);
    cout << ans << endl;
}
