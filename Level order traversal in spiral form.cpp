
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
void printSpiral(Node *root)
{
    vector<vector<int> > res;
     //Your code here
     if(root == NULL)
     {
         return;
     }
     stack<struct Node *> s1;
     stack<struct Node *> s2;

     s1.push(root);
     while(!s1.empty() || !s2.empty())
     {
         vector<int> temp1;
         int count1 (0);
         while(!s1.empty())
         {
             count1++;
             struct Node *node1 = s1.top();
             s1.pop();
             temp1.push_back(node1->data);
             if(node1->right)
             {
                 s2.push(node1->right);
             }
             if(node1->left)
             {
                 s2.push(node1->left);
             }
         }

         if(count1 != 0)
         {
             res.push_back(temp1);
         }

         vector<int> temp2;
         int count2 (0);
         while(!s2.empty())
         {
             count2++;
             struct Node *node2 = s2.top();
             s2.pop();
             temp2.push_back(node2->data);
             if(node2->left)
             {
                 s1.push(node2->left);
             }
             if(node2->right)
             {
                 s1.push(node2->right);
             }
         }
         if(count2 != 0)
         {
             res.push_back(temp2);
         }
     }

     for(int iter = 0; iter < res.size(); iter++)
     {
        for(int jter = 0; jter < res[iter].size(); jter++)
        {
            cout << res[iter][jter] << " ";
        }
     }
    // cout << endl;
}
