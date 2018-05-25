/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element
  Node is defined as
  struct Node
  {
     int data;
     Node *next;
  }
*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sortList(Node *head)
{
   //Add code here
   if(head == NULL || head->next == NULL)
   {
       return;
   }
   for(struct Node *current = head; current->next != NULL; current = current->next)
   {
       for(struct Node *selection = current->next; selection != NULL; selection = selection->next)
       {
           if(current->data > selection->data)
           {
               swap(&current->data, &selection->data);
           }
       }
   }
}
