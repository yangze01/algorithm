#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removefirst(ListNode* head){
        head = head->next;
        return head;
    }
    ListNode* addNthVal(ListNode* head,int val, int n){
        ListNode* newNode =new ListNode(val);
        if(n == 1){
            newNode->next = head;
            return newNode;
        }
        else{
            ListNode* phead = head;
            ListNode* tmp = head;
            tmp = tmp->next;
            while(n-- != 2){
                phead = phead->next;
                tmp = tmp->next;
            }
            phead->next = newNode;
            newNode->next = tmp;
            return head;
        }
    }

    ListNode* removeNthFromStart(ListNode* head, int n) {
        if(n == 1){
            head = head->next;
            return head;
        }
        else{
            ListNode* PreNode = head;
            ListNode* deleteNode = head->next;
            n--;
            while(n != 1){
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
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* res = new ListNode(0);
        res->next = head;
        ListNode* tmphead = res;
        while(n){
            head = head->next;
            n--;
        }
        while(head != NULL){
            tmphead = tmphead->next;
            head = head->next;
        }
        tmphead->next = tmphead->next->next;
        return res->next;
    }
    void travelList(ListNode* head){
        ListNode* pNode = head;
        if(pNode == NULL){
            cout<<endl;
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
void createList(ListNode* pHead){
    ListNode* p = pHead;
    for(int i = 2; i <= 5; i++){
        ListNode* pNewNode = new ListNode(i);
        p->next = pNewNode;
        p = pNewNode;
    }
}
int main(){
    Solution solution = Solution();
    ListNode* head = NULL;
    head = new ListNode(1);
    createList(head);
    solution.travelList(head);
    ListNode* res = solution.addNthVal(head,10,6);
    //solution.removeNthFromEnd(head, 2);
    //solution.removefirst(head);
    solution.travelList(res);
}
