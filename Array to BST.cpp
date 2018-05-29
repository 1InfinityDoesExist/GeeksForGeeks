#include<bits/stdc++.h>
using namespace std;

struct TNode
{
    int data;
    struct TNode *left;
    struct TNode *right;
};

struct TNode *newNode (int dat)
{
    struct TNode *node = (struct TNode *)malloc(sizeof(struct TNode));
    node->data = dat;
    node->left = NULL;
    node->right = NULL;
}
class Solution
{
    private:
    public:
        Solution();
        struct TNode *sortedToTree(vector<int> &A, int start, int end);
        void solve(vector<int> &A, int start, int end);
};
Solution::Solution(){}

void Solution::solve(vector<int> &A, int start , int end)
{
    if(start > end)
    {
        return;
    }
        int mid = start + (end-start)/2;
        cout  << A[mid] << " ";
        solve(A, start, mid-1);
        solve(A, mid+1, end);

}
void preorder(struct TNode *root)
{
    vector<int> res;
    stack<struct TNode *> s;
    s.push(root);
    while(!s.empty())
    {
        struct TNode *node = s.top();
        s.pop();
        res.push_back(node->data);
        if(node->left != NULL)
        {
            s.push(node->left);
        }
        if(node->right != NULL)
        {
            s.push(node->right);
        }
    }

    for(vector<int>::iterator iter = res.begin(); iter != res.end(); iter++)
    {
        cout << *iter << " ";
    }
}
struct TNode * Solution::sortedToTree(vector<int> &A, int start, int end)
{
    if(start > end)
    {
        return NULL;
    }
    int mid = start + (end-start)/2;
    struct TNode *root = newNode(A[mid]);
    root->left = sortedToTree(A, start, mid-1);
    root->right = sortedToTree(A, mid+1, end);
    return root;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        vector<int> A;
        int n;
        cin >> n;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }

        sol.solve(A, 0, A.size()-1);
    /*  if(A[0] < A[1])
      {
        reverse(A.begin(), A.end());
      }
        struct TNode *root = sol.sortedToTree(A, 0, A.size()-1);
        preorder(root);*/
        cout << endl;
    }
    return 0;
}
