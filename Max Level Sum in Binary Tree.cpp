int maxLevelSum(Node * root)
{
   //Your code here
   if(root == NULL)
   {
       return 0;
   }
   vector<vector<int> > res;
   queue<struct Node *> q1;
   queue<struct Node *> q2;

   q1.push(root);
   while(!q1.empty() || !q2.empty())
   {
       vector<int> temp1;
       int count1 (0);
       while(!q1.empty())
       {
           count1++;
           struct Node *node1 = q1.front();
           q1.pop();
           temp1.push_back(node1->data);
           if(node1->left)
           {
               q2.push(node1->left);
           }
           if(node1->right)
           {
               q2.push(node1->right);
           }
       }
       if(count1 != 0)
       {
           res.push_back(temp1);
       }

       vector<int> temp2;
       int count2 (0);

       while(!q2.empty())
       {
           count2++;
           struct Node *node2 = q2.front();
           q2.pop();
           temp2.push_back(node2->data);
           if(node2->left)
           {
               q1.push(node2->left);
           }
           if(node2->right)
           {
               q1.push(node2->right);
           }
       }
       if(count2 != 0)
       {
           res.push_back(temp2);
       }
   }
   vector<int> ans;
   for(int iter = 0; iter < res.size(); iter++)
   {
       vector<int> temp = res[iter];
       int sum = accumulate(temp.begin(), temp.end(), 0);
       ans.push_back(sum);
   }
   int returner = *max_element(ans.begin(), ans.end());
   return returner;
}
