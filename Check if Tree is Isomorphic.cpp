
/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/


bool isIdentical(Node *root1,Node *root2)
{
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if(root1 == NULL || root2 == NULL)
    {
        return false;
    }

    queue<struct Node *> q1;
    queue<struct Node *> q2;

    q1.push(root1);
    q2.push(root2);

    while(!q1.empty() && !q2.empty())
    {
        struct Node *node1 = q1.front();
        q1.pop();
        struct Node *node2 = q2.front();
        q2.pop();

        if(node1 == NULL && node2 == NULL)
        {
            continue;
        }
        if(node1 == NULL || node2 == NULL)
        {
            return false;
        }
        if(node1->data != node2->data)
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
bool isIsomorphic(Node *root1,Node *root2)
{
//add code here.
    if(isIdentical(root1, root2))
    {
        return true;
    }

    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if(root1 == NULL || root2 == NULL)
    {
        return false;
    }

    queue<struct Node *> q1;
    queue<struct Node *> q2;

    q1.push(root1);
    q2.push(root2);

    while(!q1.empty() && !q2.empty())
    {
        struct Node *node1 = q1.front();
        q1.pop();
        struct Node *node2 = q2.front();
        q2.pop();

        if(node1 == NULL && node2 == NULL)
        {
            continue;
        }
        if(node1 == NULL || node2 == NULL)
        {
            return false;
        }
        if(node1->data != node2->data)
        {
            return false;
        }

        q1.push(node1->left);
        q1.push(node1->right);
        q2.push(node2->right);
        q2.push(node2->left);


    }
    return true;
}
