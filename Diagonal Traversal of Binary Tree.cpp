
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
void diagonalPrint(Node *root)
{
   // your code here
   if(root == NULL)
   {
       return;
   }
   queue<struct Node *> q;
   q.push(root);
   q.push(NULL);
   while(!q.empty())
   {
       struct Node *node = q.front();
       q.pop();
       if(node == NULL)
       {
           if(q.empty())
           {
               return;
           }
           q.push(NULL);
       }
       else
       {
           while(node)
           {
               cout << node->data << " ";
               if(node->left)
               {
                   q.push(node->left);
               }
               node = node->right;
           }
       }
   }
}
