
void printSibling(Node* node)
{
   // Your code here
   if(node == NULL || (node->left == NULL && node->right == NULL))
   {
       cout << "-1";
       return;
   }
   queue<struct Node *> q;
    q.push(node);
    vector<int> res;
   while(!q.empty())
   {
       struct Node *node = q.front();
       q.pop();
       if(node->left != NULL && node->right != NULL)
       {
           q.push(node->left);
           q.push(node->right);
       }
       else if(node->left)
       {
          res.push_back(node->left->data);
           q.push(node->left);
       }
       else if(node->right)
       {
           res.push_back(node->right->data);
           q.push(node->right);
       }
   }
   if(res.size() == 0)
   {
       cout << "-1";
       return;
   }
   else
   {
       sort(res.begin(), res.end());
       for(vector<int>::iterator iter = res.begin(); iter != res.end(); iter++)
       {
           cout << *iter << " ";
       }
   }
   res.clear();
   return;
}
