#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int data) : val(data), next(NULL){}
};
class Solution
{
private:
public:
    Solution();
    struct ListNode *quickSort(struct ListNode *start, struct ListNode *end);
    struct ListNode *partition(struct ListNode *begin, struct ListNode *end);
    struct ListNode *sorting(struct ListNode *head);
};
Solution::Solution(){}

struct ListNode *Solution::partition(struct ListNode *begin, struct ListNode *end)
{
    if(begin == end)
    {
        return begin;
    }
    struct ListNode *head = begin;
    struct ListNode *temp = NULL;
    struct ListNode *pre = head;
    int value = head->val;
    while(pre != NULL)
    {
        temp = pre->next;
        if(temp == end)
        {
            break;
        }
        if(temp && temp->val < value)
        {
            pre->next = temp->next;
            temp->next = head;
            head = temp;
        }
        else{
            pre = temp;
        }
    }
    return head;
}
struct ListNode *Solution::quickSort(struct ListNode *start, struct ListNode *end)
{
    if(start == end)
    {
        return start;
    }
    struct ListNode *head = partition(start, end);
    struct ListNode *h1 = quickSort(head, start);
    struct ListNode *h2 = quickSort(start->next, end);
    start->next = h2;
    return h1;
}
struct ListNode *Solution::sorting(struct ListNode *head)
{
    return quickSort(head, NULL);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    struct ListNode *head = new ListNode(8);
    head->next = new ListNode(10);
    head->next->next = new ListNode(100);
    head->next->next->next = new ListNode(150);
    head->next->next->next->next = new ListNode(12);
    head->next->next->next->next->next = new ListNode(30);
    head->next->next->next->next->next->next = new ListNode(25);
    head->next->next->next->next->next->next->next = new ListNode(26);
    head->next->next->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next->next->next->next->next = new ListNode(14);
    head->next->next->next->next->next->next->next->next->next->next->next = new ListNode(24);

    struct ListNode *ans = sol.sorting(head);
    while(ans != NULL)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}
