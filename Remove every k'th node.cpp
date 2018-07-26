Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Link list Node
struct Node
{
    int data;
    struct Node* next;
};*/
/*You are required to complete this method*/
Node * deleteK(Node *head,int K)
{
  //Your code here
  int count (0);
  if(head == NULL)
  {
      return NULL;
  }
  if(K == 1)
  {
      free(head);
      return NULL;
  }
  struct Node *ptr = head;
  struct Node *prev = NULL;
  while(ptr != NULL)
  {
      count++;
      if(count == K)
      {
          delete(prev->next);
          prev->next = ptr->next;
          count = 0;
      }
      if(count != 0)
      {
          prev = ptr;
      }
      ptr = prev->next;
  }
  return head;
}
