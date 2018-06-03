/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*You are required to complete this function*/
int getLevelDiff(Node *root)
{
   //Your code here
    vector<int> res;
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
            if(node1->left != NULL)
            {
                q2.push(node1->left);
            }
            if(node1->right != NULL)
            {
                q2.push(node1->right);
            }
        }
        if(count1 != 0)
        {
            int x = accumulate(temp1.begin(), temp1.end(), 0);
            res.push_back(x);
        }


         vector<int> temp2;
        int count2 (0);
        while(!q2.empty())
        {
            count2++;
            struct Node *node2 = q2.front();
            q2.pop();
            temp2.push_back(node2->data);
            if(node2->left != NULL)
            {
                q1.push(node2->left);
            }
            if(node2->right != NULL)
            {
                q1.push(node2->right);
            }
        }
        if(count2 != 0)
        {
            int x = accumulate(temp2.begin(), temp2.end(), 0);
            res.push_back(x);
        }
    }
    int even = 0, odd = 0;
    for(int iter= 0; iter < res.size(); iter++)
    {
        if((iter+1)%2 == 0)
        {
            even = even + res[iter];
        }
        else
        {
            odd = odd + res[iter];
        }
    }

    return odd-even;

}
