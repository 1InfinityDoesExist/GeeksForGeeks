#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int val) : data(val), next(NULL){}
};
class Solution
{
    private:
    public:
        Solution();
        void solvekar();
};
Solution::Solution(){}
void Solution::solvekar()
{
    int n;
    cin >> n;
    struct Node *odd = NULL;
    struct Node *even = NULL;
    for(int iter = 0; iter < n; iter++)
    {
        int data;
        cin >> data;
        if(data%2 == 0)
        {
            if(even == NULL)
            {
                even = new Node(data);
            }
            else
            {
                struct Node *ptr = even;
                while(ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = new Node(data);
            }
        }
        else
        {
            if(odd == NULL)
            {
                odd = new Node(data);
            }
            else
            {
                struct Node *ptr = odd;
                while(ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = new Node(data);
            }
        }
    }
    while(even != NULL)
    {
        cout << even->data << " ";
        even = even->next;
    }

    while(odd != NULL)
    {
        cout << odd->data << " ";
        odd = odd->next;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        sol.solvekar();
        cout << endl;
    }
    return 0;
}
