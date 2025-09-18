#include <iostream>
using namespace std;
 // Definition for singly-linked list.
 // question for merging sorted Linked list
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *last=nullptr;
        ListNode *third= nullptr;
        ListNode *result=nullptr;

        if(!list1) return list2;
        else if(!list2) return list1;
        
        if(list1->val < list2->val)
        {

            last=third=list1;
            list1=list1->next;
            last->next=nullptr;

        }
        else
        {
            last=third=list2;
            list2=list2->next;
            last->next=nullptr;
        }
        while(list1!=nullptr && list2!=nullptr)
        {
            if(list1->val <list2->val)
            {
                last->next=list1;
                last=list1;
                list1=list1->next;
                last->next=nullptr;
            }
            else 
            {
                last->next=list2;
                last=list2;
                list2=list2->next;
                last->next=nullptr;
            }
        }
            if(list1!=nullptr)
            {
                last->next=list1;
                
            }
            else
            {
                last->next=list2;
            }
        
        return third;

    }
    
};