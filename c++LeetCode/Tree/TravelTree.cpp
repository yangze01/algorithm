#include<iostream>
#include<string>
#include<stack>
#include<fstream>

const int MAX_N = 100;
//���ݽڵ�
class BinaryTreeNode{
public:
  int m_nValue;
  BinaryTreeNode* m_pLeft;
  BinaryTreeNode* m_pRight;
};
// ������
class Tree{
public:
  Tree(){}
  ~Tree(){}
  stack<BinaryTreeNode*> m_stack;
  m_stack.push()
  //��������ǵݹ��㷨
  void PreOrderTraverse(){
    if(t == nullptr){
      return;
    }
    stack<Node*> m_stack;
    
  }

private:
  BinaryTreeNode *t;
}
