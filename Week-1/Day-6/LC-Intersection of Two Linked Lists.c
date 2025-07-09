Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
For example, the following two linked lists begin to intersect at node c1:
The test cases are generated such that there are no cycles anywhere in the entire linked structure.
Note that the linked lists must retain their original structure after the function returns.

  struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (!headA || !headB) return NULL;

    struct ListNode *pA = headA;
    struct ListNode *pB = headB;

    while (pA != pB) {
        pA = (pA != NULL) ? pA->next : headB;
        pB = (pB != NULL) ? pB->next : headA;
    }

    return pA;
}
