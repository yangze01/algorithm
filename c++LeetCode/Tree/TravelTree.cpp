#include<iostream>
#include<string>
#include<stack>
#include<fstream>

const int MAX_N = 100;
//数据节点
class BinaryTreeNode{
public:
  int m_nValue;
  BinaryTreeNode* m_pLeft;
  BinaryTreeNode* m_pRight;
};
// 二叉树
class Tree{
public:
  Tree(){}
  ~Tree(){}
  stack<BinaryTreeNode*> m_stack;
  m_stack.push()
  //先序遍历非递归算法
  void PreOrderTraverse(){
    if(t == nullptr){
      return;
    }
    stack<Node*> m_stack;
    
  }

private:
  BinaryTreeNode *t;
}
