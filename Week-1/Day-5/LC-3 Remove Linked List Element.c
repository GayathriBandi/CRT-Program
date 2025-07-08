Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
  
Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

  struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) {
        head = head->next;
    }

    struct ListNode* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->next->val == val) {
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }

    return head;
}
