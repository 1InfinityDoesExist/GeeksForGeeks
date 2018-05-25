
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*  Structure of a Binary Tree
struct Node
{
    int data;
    Node* left, *right;
}; */
/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root)
{
   // Your code here

   if(root == NULL)
   {
       return 0;
   }
   int result (0);
   queue<struct Node *> q;
   q.push(root);
   while(!q.empty())
   {
       int count = q.size();
       result = max(result, count);
       while(count--)
       {
           struct Node *node = q.front();
           q.pop();
           if(node->left)
           {
               q.push(node->left);
           }
           if(node->right)
           {
               q.push(node->right);
           }
       }
   }
   return result;
}
