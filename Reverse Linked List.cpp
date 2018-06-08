#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data) : val(data), next(NULL){}
};
class Solution
{
private:
public:
    Solution();
    void printListValue(struct ListNode *head);
    struct ListNode *reverseList(struct ListNode *head);
};
Solution::Solution(){}
void Solution::printListValue(struct ListNode *head)
{
    if(head == NULL)
    {
        return;
    }
    struct ListNode *ptr = head;
    while(ptr != NULL)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    return;
}
struct ListNode *Solution::reverseList(struct ListNode *head)
{
    if(head == NULL)
    {
        return NULL;
    }
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *next;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);

    sol.printListValue(head);//printing the linked list thats it..

    struct ListNode *a = sol.reverseList(head);
    cout << endl;

    sol.printListValue(a);

    return 0;
}
