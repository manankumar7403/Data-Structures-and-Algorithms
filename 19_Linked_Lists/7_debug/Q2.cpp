/*
ListNode* middleNode(ListNode* head) {
        ListNode* last = head;
        ListNode* first = head;

        while (first->next != NULL && last != NULL) {
            last = last->next;
            first = first->next->next;
        }
    
        return last;
    }
*/

ListNode *middleNode(ListNode *head)
{
    ListNode *last = head;
    ListNode *first = head;

    while (first != NULL && first->next != NULL)
    {
        first = first->next;
        if(first->next != NULL)
        {
            first = first->next;
            last = last->next;
        }
    }
    return last;
}