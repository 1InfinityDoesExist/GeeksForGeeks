Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Link list Node
struct Node
{
    int data;
    struct Node* next;
}; */
// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node *head)
{
     // Your Code Here

     if(head == NULL)
     {
         return head;
     }
     int len (0);
     struct Node *current = head;
     while(current != NULL)
     {
         len++;
         current = current->next;
     }

     current = head;
     struct Node *prev = NULL;
     for(int iter = 0; iter < len/2; iter++)
     {
         prev = current;
         current = current->next;
     }
     prev->next = current->next;
     free(current);
     return head;
}
