class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL){
			return head;
		}
        ListNode* smallAns = deleteDuplicates(head->next);
        if(head->val == smallAns->val) return smallAns;
        head -> next = smallAns;
        return head;
    }
};