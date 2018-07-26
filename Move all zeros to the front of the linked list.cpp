{
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;
struct Node
{
int data;
struct Node* next;
};
void push(struct Node **head_ref, int new_data) {
struct Node *new_node = new Node;
new_node->data = new_data;
new_node->next = (*head_ref);
(*head_ref) = new_node;
}
void moveZeroes(struct Node **head);
// function to displaying nodes
void display(struct Node *head) {
while (head != NULL) {
	cout << head->data << " ";
	head = head->next;
}
cout <<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int q;
        struct Node *Head=NULL;
        for(int i=0;i<n;i++)
        {
            cin>>q;
            push(&Head,q);
        }
        moveZeroes(&Head);
        display(Head);
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
/* Linked List Node structure
struct Node
{
int data;
struct Node* next;
};
*/
// Move Zeros to the front of the list
void moveZeroes(struct Node **head)
{
    //Your code here
    struct Node *temp = *head;
    while(temp->next != NULL)
    {
        if(temp->next->data == 0)
        {
            struct Node *p = temp->next;
            temp->next = p->next;
            p->next = *head;
            *head = p;
        }
        else
        {
            temp = temp->next;
        }
    }
}
