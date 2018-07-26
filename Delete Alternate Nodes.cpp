Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of the node of the binary tree
struct Node
{
	int data;
	struct Node *next;
};
*/
// Complete this function
void deleteAlt(struct Node *head){

    // Code here
    if(head == NULL)
    {
        return;
    }
    struct Node *prev = head;
    struct Node *node = head->next;

    while(prev != NULL && node != NULL)
    {
        prev->next = node->next;
        free(node);
        prev = prev->next;
        if(prev != NULL)
        {
            node = prev->next;
        }
    }
}
