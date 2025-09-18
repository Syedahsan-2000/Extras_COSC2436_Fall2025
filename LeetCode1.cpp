#include <iostream>
using namespace std;
  //Definition for singly-linked list.
  // Reversing a Linked List Leetcode Easy problem Lines 14-28
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head;      // Pointer to the current node being processed
        ListNode *second = nullptr; // Will become the new head of the reversed list
        ListNode *third = nullptr;  // Temporary pointer to store the previous node

        while (curr != nullptr) {   // Traverse the entire list
            third = second;         // Store previous node
            second = curr;          // Move 'second' to current node
            curr = curr->next;      // Advance 'curr' to next node
            second->next = third;   // Reverse the link: point current node to previous node
        }

        return second;              // 'second' is now the head of the reversed list
    }
};
