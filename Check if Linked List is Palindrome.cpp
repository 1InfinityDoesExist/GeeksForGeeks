Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of the Node is
struct Node
{
    int data;
    struct Node* next;
};*/
/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    //Your code here
    if(head == NULL || head->next == NULL)
    {
        return true;
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
    for(int iter = 0; iter < len/2 ; iter++)
    {
        prev = current;
        current = current->next;
    }

    struct Node *previous = NULL;
    struct Node *next;
    while(current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    prev->next = previous;
    current = head;


    for(int iter = 0; iter < len/2; iter++)
    {
        if(current->data != prev->next->data)
        {
            return false;
        }
        current = current->next;
        prev->next = prev->next->next;
    }
    return true;
}
