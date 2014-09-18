#include<vector>
#include<iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {

        if(head == NULL) return NULL;
        int pval = head->val;
        ListNode *pt = head->next;
        ListNode *prev = head;
        ListNode *first = head;

        while(pt!=NULL){
            if(pt->val != pval){
                prev->next = pt;
                prev = prev->next;
                pval = pt->val;
            }
            pt= pt->next;

        }
        prev->next = NULL;
    return first;
    }
};
