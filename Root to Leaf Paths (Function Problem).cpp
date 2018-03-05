/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Structure of Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/
/* The function should print all the paths from root
 to leaf nodes of the binary tree */
 void dfs(struct Node *root, string str, vector<string> &res)
 {
     if(root == NULL)
     {
         return;
     }
     if(str == "")
     {
         str += to_string(root->data);
     }
     else
     {
         str += " " + to_string(root->data);
     }
     if(root->left == NULL && root->right == NULL)
     {
         res.push_back(str);
     }
     dfs(root->left, str, res);
     dfs(root->right, str, res);
 }
void printPaths(Node* root)
{
    // Code here
    string str = "";
    vector<string> res;
    dfs(root, str, res);
    for(vector<string>::iterator iter = res.begin(); iter != res.end(); iter++)
    {
        string s = *iter;
        cout << s << " #";
    }
    cout << endl;
}
