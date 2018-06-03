/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */
/* Given two trees, should return true if they are
   mirror of each other. */
int areMirror(Node* a, Node* b)
{
   // Your code here
   if(a == NULL && b == NULL)
   {
       return true;
   }
   if(a == NULL || b == NULL)
   {
       return false;
   }

   stack<struct Node *> s;
   s.push(a);
   while(!s.empty())
   {
       struct Node *node = s.top();
       s.pop();
       if(node)
       {
           s.push(node->left);
           s.push(node->right);
           swap(node->left, node->right);
       }
   }

   queue<struct Node *> q1;
   queue<struct Node *> q2;
   q1.push(a);
   q2.push(b);
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
