/*
ListNode* deleteMiddle(ListNode* head) {
        if (head -> next == NULL && head == NULL)
            return NULL;
        
        ListNode *slow = head, *fast = head -> next -> next;
        
        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow -> next = fast;
        return head;
    }
*/

ListNode *deleteMiddle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    ListNode *slow = head, *fast = head->next->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast -> next;
        if(fast -> next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    slow->next = slow->next->next;
    return head;
}