// Has Cycle detection Linked list


bool has_cycle(SinglyLinkedListNode* head) {
    if (!head) return false;

    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // move slow pointer by 1
        fast = fast->next->next;     // move fast pointer by 2

        if (slow == fast) {          // cycle detected
            return true;
        }
    }

    return false; // no cycle
}
