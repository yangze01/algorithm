#include<iostream>
#include<stdio.h>
/*
  ������ĩβ���Ԫ�أ�ΪʲôҪ��ָ��ָ���ָ��
*/

struct ListNode{
  int m_nValue;
  ListNode* m_pNext;
};
ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = nullptr;

    return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == nullptr)
    {
        printf("Error to connect two nodes.\n");
        //exit(1);
    }

    pCurrent->m_pNext = pNext;
}


void PrintList(ListNode* pHead)
{
    printf("PrintList starts.\n");

    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->m_nValue);
        pNode = pNode->m_pNext;
    }

    printf("\nPrintList ends.\n");
}

void AddToTail(ListNode** pHead, int value){
  ListNode* pNew = new ListNode();
  pNew->m_nValue = value;
  pNew->m_pNext = nullptr;
  if(*pHead == nullptr){
    *pHead = pNew;
  }
  else{
    ListNode* p = *pHead;
    while(p->m_pNext != nullptr){
      p = p->m_pNext;
    }
    p->m_pNext = pNew;
  }
}


void AddToTail2(ListNode* pHead, int value){
  ListNode* pNew = new ListNode();
  pNew->m_nValue = value;
  pNew->m_pNext = nullptr;
  if(pHead == nullptr){
    pHead = pNew;
  }
  else{
    ListNode* p = pHead;
    while(p->m_pNext != nullptr){
      p = p->m_pNext;
    }
    p->m_pNext = pNew;
  }
}

int main(){
  std::cout<<"Hello World!"<<std::endl;
  ListNode* head = nullptr;
  AddToTail2(head, 10);
  if(head != nullptr){
    std::cout<<head->m_nValue<<std::endl;
  }
  else{
    std::cout<< "head is nullptr"<<std::endl;
  }

  AddToTail(&head, 15);
  if(head != nullptr){
    std::cout<<head->m_nValue<<std::endl;
  }
  else{
    std::cout<< "head is nullptr"<<std::endl;
  }


  return 0;
}
