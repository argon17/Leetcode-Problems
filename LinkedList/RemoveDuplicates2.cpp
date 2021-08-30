class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL){
			return head;
		}
        if(head->val != head->next->val){
            head->next = deleteDuplicates(head->next);
            return head;
        }
        int val = head->val;
        while(head && head->val == val)
            head = head->next;
        return deleteDuplicates(head);
    }
};