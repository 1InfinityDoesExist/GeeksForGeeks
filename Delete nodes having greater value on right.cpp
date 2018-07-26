{
#include<bits/stdc++.h>
using namespace std;
struct Node
{
int data;
Node* next;
};
Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}
Node *compute(Node *head);
int main()
{
    int T;
	cin>>T;
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=newNode(data);
			else
			{
				temp->next = newNode(data);
				temp=temp->next;
			}
		}
        Node *result = compute(head);
        print(result);
        cout<<endl;
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure of linked list is the following
struct Node
{
int data;
Node* next;
};
*/
struct Node *reverse(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
Node *compute(Node *head)
{
// your code goes here
    if(head == NULL)
    {
        return head;
    }
    struct Node *rev_head = reverse(head);
    struct Node *first = rev_head;
    struct Node *second = rev_head->next;
    while(second != NULL)
    {
        if(second->data < first->data)
        {
            struct Node *temp = second;
            second = second->next;
            first->next = temp->next;
            free(temp);
        }
        else
        {
            first = second;
            second = second->next;
        }
    }
    struct Node *new_head = reverse(rev_head);
    return new_head;

}
