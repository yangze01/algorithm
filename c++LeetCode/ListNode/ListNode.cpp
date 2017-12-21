#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromStart(ListNode* head, int n) {
        if(n == 1){
            return head->next;
        }
        else{
            ListNode* PreNode = head;
            ListNode* deleteNode = head->next;
            n--;
            while(n != 0){
                cout<<PreNode->val<<" "<<deleteNode->val<<endl;
                PreNode = PreNode->next;
                deleteNode = deleteNode->next;
                n--;
            }
            PreNode->next = deleteNode->next;
            deleteNode->next = NULL;
            return head;
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 1){
            return head->next;
        }
        else{
            ListNode* PreNode = head;

        }
        return head;
    }
    void createList(ListNode* &pHead){
        pHead = new ListNode(1);
        ListNode* p = pHead;
        for(int i = 2; i <= 5; i++){
            ListNode* pNewNode = new ListNode(i);
            p->next = pNewNode;
            p = pNewNode;
        }
    }
    void travelList(ListNode* head){
        ListNode* pNode = head;
        if(pNode == NULL){
            return;
        }
        else{
            cout<<pNode->val;
            pNode = pNode->next;
            while(pNode != NULL){
                cout<<"->"<<pNode->val;
                pNode = pNode->next;
            }
        }
        cout<<endl;
    }
};

int main(){
    Solution solution = Solution();
    ListNode* head = NULL;
    solution.createList(head);
    solution.travelList(head);
    solution.removeNthFromStart(head,2);
    solution.travelList(head);
}
