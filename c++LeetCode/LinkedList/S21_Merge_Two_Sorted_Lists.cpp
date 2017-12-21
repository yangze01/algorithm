#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode *removefirst(ListNode *head) {
    head = head->next;
    return head;
  }
  ListNode *addNthVal(ListNode *head, int val, int n) {
    ListNode *newNode = new ListNode(val);
    if (n == 1) {
      newNode->next = head;
      return newNode;
    } else {
      ListNode *phead = head;
      ListNode *tmp = head;
      tmp = tmp->next;
      while (n-- != 2) {
        phead = phead->next;
        tmp = tmp->next;
      }
      phead->next = newNode;
      newNode->next = tmp;
      return head;
    }
  }

  ListNode *removeNthFromStart(ListNode *head, int n) {
    if (n == 1) {
      head = head->next;
      return head;
    } else {
      ListNode *PreNode = head;
      ListNode *deleteNode = head->next;
      n--;
      while (n != 1) {
        cout << PreNode->val << " " << deleteNode->val << endl;
        PreNode = PreNode->next;
        deleteNode = deleteNode->next;
        n--;
      }
      PreNode->next = deleteNode->next;
      deleteNode->next = NULL;
      return head;
    }
  }
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *res = new ListNode(0);
    res->next = head;
    ListNode *tmphead = res;
    while (n) {
      head = head->next;
      n--;
    }
    while (head != NULL) {
      tmphead = tmphead->next;
      head = head->next;
    }
    tmphead->next = tmphead->next->next;
    return res->next;
  }

  void travelList(ListNode *head) {
    ListNode *pNode = head;
    if (pNode == NULL) {
      cout << endl;
    } else {
      cout << pNode->val;
      pNode = pNode->next;
      while (pNode != NULL) {
        cout << "->" << pNode->val;
        pNode = pNode->next;
      }
    }
    cout << endl;
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
void createList(ListNode *pHead) {
  ListNode *p = pHead;
  int x;
  cout << "please input number: " << endl;
  cin >> x;
  while (x != 0) {
    ListNode *pNewNode = new ListNode(x);
    p->next = pNewNode;
    p = pNewNode;
    cin >> x;
  }
}
int main() {
  Solution solution = Solution();
  ListNode *head1 = new ListNode(1);
  ListNode *head2 = new ListNode(2);
  createList(head1);
  createList(head2);
  solution.travelList(head1);
  solution.travelList(head2);
  ListNode *hh = solution.mergeTwoLists(head1, head2);
  solution.travelList(hh);
}
