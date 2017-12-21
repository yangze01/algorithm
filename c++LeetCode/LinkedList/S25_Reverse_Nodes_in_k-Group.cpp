#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
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

  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *res = new ListNode(0);
    res->next = head;
    head = res;
    while (head->next != NULL) {
      head = reverseKNodes(head, k);
    }
    return res->next;
  }
  ListNode *reverseKNodes(ListNode *head, int k) {
    ListNode *node = head;
    for (int i = 0; i < k; i++) {
      if (node->next == NULL) {
        return node;
      }
      node = node->next;
    }
    ListNode *pre = head;
    ListNode *cur = pre->next;
    while (pre->next != node) {
      ListNode *tmp = pre->next;
      pre->next = cur->next;
      cur->next = cur->next->next;
      pre->next->next = tmp;
    }
    return cur;
  }

  ListNode *reverse_List(ListNode *head) {
    ListNode *res = new ListNode(0);
    res->next = head;
    ListNode *pre = res;
    ListNode *cur = head;
    while (cur->next != NULL) {
      ListNode *tmp = pre->next;
      pre->next = cur->next;
      cur->next = cur->next->next;
      pre->next->next = tmp;
    }
    return res->next;
  }
};

void createList(ListNode *pHead) {
  ListNode *p = pHead;
  for (int i = 2; i <= 10; i++) {
    ListNode *pNewNode = new ListNode(i);
    p->next = pNewNode;
    p = pNewNode;
  }
}

int main() {
  Solution solution = Solution();
  ListNode *head1 = new ListNode(1);
  createList(head1);
  solution.travelList(head1);
  ListNode *rhead = solution.reverseKGroup(head1, 3);
  solution.travelList(rhead);
}
