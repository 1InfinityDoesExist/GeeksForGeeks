

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
void printLeaves(struct Node *root)
{
    if(root)
    {
        if(root->left)
        {
            printLeaves(root->left);
        }
        if(root->left == NULL && root->right == NULL)
        {
            cout << root->data << " ";
        }
        if(root->right)
        {
            printLeaves(root->right);
        }
    }
}

void printBoundaryRight(struct Node *root)
{
    if(root)
    {
        if(root->right)
        {
            printBoundaryRight(root->right);
            cout << root->data << " ";
        }
        else if(root->left)
        {
            printBoundaryRight(root->left);
            cout << root->data << " ";
        }
    }
    return;
}

void printBoundaryLeft(struct Node *root)
{
   if(root)
   {
        if(root->left)
        {
            cout << root->data << " ";
            printBoundaryLeft(root->left);
        }
        else if(root->right)
        {
            cout << root->data << " ";
            printBoundaryRight(root->right);
        }
   }
    return;
}
void printBoundary(Node *root)
{
     //Your code here
     if(root == NULL)
     {
         return;
     }
     cout << root->data << " ";
     printBoundaryLeft(root->left);
     printLeaves(root);
     printBoundaryRight(root->right);
     return;
}
