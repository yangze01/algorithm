# S23 Merge k Sorted Lists

[TOC]

## 题目描述
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

该题目拓展于之前的一个题目Merge Two Sorted List. 题目要求分析算法的复杂度，所以该题目在于对链表合并复杂度的分析。

## 算法1(Merge Two Sorted List)
常规思路：来源于合并两个有序链表，即循环合并链表，每次用合并后的新链表与下一个链表使用Merge Two Sorted List合并。

分析：
　　对于两个有序链表的合并，假设l1的长度为m，l2的长度为n，则需要最多遍历$O(m+n)$。
假设链表的平均长度为n，则
　　k =1，即合并第一个链表，遍历0次
　　k=2，即合并1，2链表，遍历n+n次，2n
　　k=3, 合并1,2和3，链表，遍历n+n+n次,3n
合并第(k-1)和第k个链表，遍历kn次,所以总共需要遍历$n*(2+3+...+k)$次，即$\frac{n*(k^2+k-2)}{3}$次，时间复杂度为$O(n*k^2)$，代码如下：
```cpp
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
```
## 算法2(divided and conquer)
思路：利用分治法的思想，假设一共有k个待合并链表，链表的平均长度为n，合并k个问题转换为合并两个$\frac{k}{2}$个链表的合并，链表长度不断增加，$n \rightarrow kn$，第k次合并需要$n*2^k$次遍历，所以总的时间复杂度为O(nklogk)。
一个取巧的算法，用同一个List进行分治：
```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        while(lists.size()>1){

            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* tmp = res;
        ListNode* Phead1 = l1;
        ListNode* Phead2 = l2;
        while(Phead1 != NULL && Phead2 != NULL){
            if(Phead1->val < Phead2->val){
                tmp->next = Phead1;
                tmp = tmp->next;
                Phead1 = Phead1->next;
            }
            else{
                tmp->next = Phead2;
                tmp = tmp->next;
                Phead2 = Phead2->next;
            }
        }
        if(Phead1 == NULL){
            tmp->next = Phead2;
        }
        else{
            tmp->next = Phead1;
        }
        return res->next;
    }

};
```
##算法3 (Priority_queue)
在介绍算法3之前，先说明要用到的一些数据结构
### 堆
				   18
				  /	\
				 10	 16
				/ \   / \
				9  5  8  12

 18, 10, 16, 9, 5, 8, 12
上图是大根堆，即根节点比子节点的值都大，对应的小根堆为根节点比子节点的值都小。
### 优先队列
优先队列是队列的一种，优先队列默认使用大根堆，即值最大的优先级最高。
c++中优先队列的定义为：
> priority_queue<Type,Container,Functional>
分别代表数据类型(Type)，保存数据的容器(Container)，比较函数的定义(Functional)
比较函数用来决定优先次序，默认为<，即最大值在顶端
### 算法实现
**算法思路：**
该算法通过将每个链表的头结点取出，建立一个小根堆，因为每个链表均为排好序的，所以每次取得头结点均为每个链表的最小值，每次取堆顶的元素就是k个链表的最小值，取完堆顶元素，将该元素所在的链表向后移动一位。
**时间复杂度：**
建堆的时间复杂度是$\frac{k}{2}*logk$,每次去除堆顶再加入的时间复杂度为$logk$,一共需要n(k-1)次，时间复杂度为$O(nklogk)$
#### priority_queue方法，只能获得最顶部的元素

```cpp

struct compare{
	bool operator()(const ListNode *l, const ListNode* r){
		return l->val > r->val;
	}
};
//priority_queue
ListNode* mergeLists(vector<ListNode*> &lists){
	priority_queue<ListNode*, vector<ListNode*>, compare> q;
	for(auto l : lists){
		if(l) q.push(l);
	}
	if(q.empty()) return NULL;
	ListNode* result = q.top();
	q.pop();
	if(result->next) q.push(result->next);
	ListNode* tail = result;
	while(!q.empty()){
		tail->next = q.top();
		q.pop();
		tail = tail->next;
		if(tail->next) q.push(tail->next);
	}
	return result;
}
```

#### make_headp方法，可以访问所有元素
```cpp
static bool heapComp(ListNode* a, ListNode* b){
	return a->val > b->val;
}
ListNde* mergeKLists(vector<ListNode*> & lists){
	ListNode* head(0);
	ListNode* curNode = &head;
	vector<ListNode*> v;
	for(int i = 0; i < lists.size(); i++){
		if(lists[0]) v.push_back(lists[i]);
	}
	make_heap(v.begin(), v.end(),heapComp);
	while(v.size()>0){
		curNode->next = v.front();
		pop_head(v.begin(), v.end(), heapComp);
		v.pop_back();
		curNode = curNode->next;
		if(curNode->next){
			v.push_back(curNode->next);
			push_heap(v.begin(), v.end(), heapComp);
		}
	}
	return head->next;
}
```
