/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(slow != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow->next)
                return true;
        }
        
        return false;
    }
};
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next;
            if(fast->next!=NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
            
            if(slow == fast)
                return true;
        }
        
        return false;
    }
};