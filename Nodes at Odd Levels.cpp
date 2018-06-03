/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// your task is to complete the function
void printOddNodes(Node *root)
{
    // Code here
    if(root == NULL)
    {
        cout << " " <<endl;
        return;
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
            res.push_back(temp2);
        }
    }

    for(int iter = 0; iter < res.size(); iter = iter+2)
    {
        for(int jter = 0; jter < res[iter].size(); jter++)
        {
            cout << res[iter][jter] << " ";
        }
    }
    cout << endl;
    return;

}
