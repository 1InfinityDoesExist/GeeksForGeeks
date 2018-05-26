
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left;
     Node* right;
}; */
/* Computes the number of nodes in a tree. */
int getSize(Node* node)
{
   // Your code here
   if(node == NULL)
   {
       return 0;
   }
   queue<struct Node *> q;
   q.push(node);
   int count (0);
   while(!q.empty())
   {
       struct Node *temp = q.front();
       q.pop();
       count++;
       if(temp->left)
       {
           q.push(temp->left);
       }
       if(temp->right)
       {
           q.push(temp->right);
       }
   }
   return count;
}
