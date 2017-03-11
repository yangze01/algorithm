/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *res = new ListNode(INT_MIN);
    for (auto i = lists.begin(); i != lists.end(); i++) {
      res = mergeTwoLists(res, *i);
    }
    return res->next;
  }
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *res = new ListNode(0);
    ListNode *tmp = res;
    ListNode *Phead1 = l1;
    ListNode *Phead2 = l2;
    while (Phead1 != NULL && Phead2 != NULL) {
      if (Phead1->val < Phead2->val) {
        tmp->next = Phead1;
        tmp = tmp->next;
        Phead1 = Phead1->next;
      } else {
        tmp->next = Phead2;
        tmp = tmp->next;
        Phead2 = Phead2->next;
      }
    }
    if (Phead1 == NULL) {
      tmp->next = Phead2;
    } else {
      tmp->next = Phead1;
    }
    return res->next;
  }
};
