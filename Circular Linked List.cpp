

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node
struct Node {
    int data;
    Node* next;
}; */
/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
   // Your code here
   if(!head)
   {
       return true;
   }
   struct Node *ptr = head->next;
   while(ptr != NULL && ptr != head)
   {
       ptr = ptr->next;
   }
   return (ptr == head);
}
