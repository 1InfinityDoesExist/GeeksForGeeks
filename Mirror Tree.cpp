
/* Should convert tree to its mirror */
void mirror(Node* node)
{
     // Your Code Here
     if(node == NULL)
     {
         return;
     }
     stack<struct Node *> s;
     s.push(node);
     while(!s.empty())
     {
         struct Node *temp = s.top();
         s.pop();
         if(temp)
         {
             s.push(temp->left);
             s.push(temp->right);
             swap(temp->left, temp->right);
         }
     }
     return;
}
