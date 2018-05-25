
/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/*you are required to
complete this function */
bool hasPathSum(Node *node, int sum)
{
   //Your code here
   if(node == NULL)
   {
       return false;
   }
   if(node->left == NULL && node->right == NULL)
   {
       return node->data == sum;
   }
   int remaining = sum - node->data;
   return hasPathSum(node->left, remaining) || hasPathSum(node->right, remaining);
}
