

/*The structure of linked list is the following
struct node
{
int data;
node* next;
};*/
int detectloop(struct node *list){
    struct node *slow = list;
    struct node *fast = list;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return 1;
        }
    }
    return 0;
// your code goes here
}
