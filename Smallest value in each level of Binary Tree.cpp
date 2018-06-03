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
    vector<int> smallestValueAtEachLevel(struct TreeNode *root);
};

Solution::Solution(){}

vector<int> Solution::smallestValueAtEachLevel(struct TreeNode *root)
{
    vector<int> ans;
    if(root == NULL)
    {
        return ans;
    }
    queue<struct TreeNode *> q1;
    queue<struct TreeNode *> q2;
    q1.push(root);
    while(!q1.empty() || !q2.empty())
    {
        vector<int> temp1;
        int count1 (0);
        while(!q1.empty())
        {
            count1++;
            struct TreeNode *node1 = q1.front();
            q1.pop();
            temp1.push_back(node1->val);
            if(node1->left)
            {
                q2.push(node1->left);
            }
            if(node1->right)
            {
                q2.push(node1->right);
            }
        }
        if(count1 != 0)
        {
            ans.push_back(*max_element(temp1.begin(), temp1.end()));
        }

        vector<int> temp2;
        int count2 (0);
        while(!q2.empty())
        {
            count2++;
            struct TreeNode *node2 = q2.front();
            q2.pop();
            temp2.push_back(node2->val);
            if(node2->left)
            {
                q1.push(node2->left);
            }
            if(node2->right)
            {
                q1.push(node2->right);
            }
        }
        if(count2 != 0)
        {
            ans.push_back(*min_element(temp2.begin(), temp2.end()));
        }
    }
    return ans;
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
    vector<int> ans = sol.smallestValueAtEachLevel(a);
    for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}
