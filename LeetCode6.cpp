/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// Removing Nth node from End linked list
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if (head == nullptr) return nullptr;

        
        int count = 0;
        ListNode* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }

        
        int target = count - n;

        // if the head needs to be removed
        if (target == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // second pass: go to the node just before the one to remove
        current = head;
        for (int i = 0; i < target - 1; i++) {
            current = current->next;
        }

        // remove the target node
        ListNode* toDelete = current->next;
        current->next = current->next->next;
        delete toDelete;

        return head;
    }
};