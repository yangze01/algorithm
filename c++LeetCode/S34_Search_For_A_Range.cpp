#include <stdio.h>
#include <stdlib.h>

typedef struct LISTNODE {
  int data;
  struct LISTNODE *nextPtr;
} LISTNODE, *LISTNODEPTR;
LISTNODEPTR createFIFOLIST();
int findmax(LISTNODEPTR headptr);
int findmin(LISTNODEPTR headptr);
int sum(LISTNODEPTR headptr);
void destroyList(LISTNODEPTR headptr);
int main() {
  LISTNODEPTR headptr = NULL;

  headptr = createFIFOLIST();
  int MAX = 0, MIN = 0, SUM = 0;
  MAX = findmax(headptr);
  MIN = findmin(headptr);
  SUM = sum(headptr);
  printf("The maximum,minmum and the total are:%d %d %d", MAX, MIN, SUM);
  destroyList(headptr);
  headptr = NULL;

  return 0;
}
LISTNODEPTR createFIFOLIST() {
  int num;
  LISTNODEPTR headptr = NULL;
  LISTNODEPTR lastPtr = NULL;
  LISTNODEPTR currentPtr = NULL;
  printf("Please input a series of integers:");
  scanf("%d", &num);
  while (num != -1) {
    currentPtr = (LISTNODEPTR)malloc(sizeof(LISTNODE)); /*分配结点内存*/

    if (currentPtr != NULL) { /*插入结点*/
      currentPtr->data = num;
      if (headptr = NULL) { /*如果currentPtr是头节点*/
        headptr = currentPtr;
        lastPtr = currentPtr;
      } else {
        lastPtr->nextPtr = currentPtr; /*将结点连上链表尾结点*/
        lastPtr = currentPtr; /*使lastPtr指向当前链表的最后一个结点*/
      }
      scanf("%d", &num);
    }
  }
  lastPtr->nextPtr = NULL; /*设置链表结束标记*/
  return headptr;
}
int findmax(LISTNODEPTR headptr) {
  int max;
  LISTNODEPTR maxptr;
  if (headptr->nextPtr = NULL) /*若这是最后一个结点*/
    return headptr->data;
  else {
    max = findmax(headptr->nextPtr); /*找后续结点中的最大结点，由maxPtr指向*/
    if (headptr->data > maxptr->data)
      return headptr->data;
    else
      return maxptr->data;
  }
}

int findmin(LISTNODEPTR headptr) {
  int min;
  LISTNODEPTR minptr;
  if (headptr->nextPtr = NULL) /*若这是最后一个结点*/
    return headptr->data;
  else {
    min = findmin(headptr->nextPtr); /*找后续结点中的最小结点，由minPtr指向*/
    if (headptr->data < minptr->data)
      return headptr->data;
    else
      return minptr->data;
  }
}

int sum(LISTNODEPTR currentPtr) {
  int sum = 0;
  while (currentPtr != NULL) {
    sum = sum + currentPtr->data;
    currentPtr = currentPtr->nextPtr;
  }
  return sum;
}

void destroyList(LISTNODEPTR headptr) {
  LISTNODEPTR tempPtr;
  while (headptr != NULL) {
    tempPtr = headptr;
    headptr = headptr->nextPtr; /*headPtr指向下一个要删除的结点*/
    free(tempPtr);
  }
}
