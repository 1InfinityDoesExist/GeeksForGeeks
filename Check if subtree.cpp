
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isIdentical (struct TreeNode *s1, struct TreeNode *s2)
    {
        queue<struct TreeNode *> q1;
        queue<struct TreeNode *> q2;
        q1.push(s1);
        q2.push(s2);
        while(!q1.empty() || !q2.empty())
        {
            struct TreeNode *node1 = q1.front();
            q1.pop();
            struct TreeNode *node2 = q2.front();
            q2.pop();
            if(node1 == NULL && node2 == NULL)
            {
                continue;
            }
            if(node1 == NULL || node2 == NULL)
            {
                return false;
            }
            if(node1->val != node2->val)
            {
                return false;
            }
            q1.push(node1->left);
            q1.push(node1->right);
            q2.push(node2->left);
            q2.push(node2->right);
        }
        return true;
    }
    bool isSubtree(TreeNode* s, TreeNode* t)
    {
        if(s == NULL && t == NULL)
        {
            return true;
        }
        if(t == NULL)
        {
            return true;
        }
        if(s == NULL)
        {
            return false;
        }
        if(isIdentical(s, t))
        {
            return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
