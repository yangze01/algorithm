#include<iostream>
#include<fstream>
#include <stdexcept>
#include<iostream>
#include<stack>
#include<queue>
struct BinaryTreeNode
{
    int                    m_nValue;
    BinaryTreeNode*        m_pLeft;
    BinaryTreeNode*        m_pRight;
};

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder,
                              int* startInorder, int* endInorder);
BinaryTreeNode* Construct(int* preorder, int* inorder, int length);
BinaryTreeNode* CreateBinaryTreeNode(int value);
void ConnectTreeNodes(BinaryTreeNode* pParent,
                      BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
void PrintTree(const BinaryTreeNode* pRoot);
void DestroyTree(BinaryTreeNode* pRoot);
void PrintTreeNode(const BinaryTreeNode* pNode);
// ���ı����㷨ʵ��

// �ݹ����ʵ��
void PreOrderRecursion(BinaryTreeNode* T){

// �ݹ�ǰ�����
  if(T != nullptr){
    std::cout<<T->m_nValue<<" ";
    PreOrderRecursion(T->m_pLeft);
    PreOrderRecursion(T->m_pRight);
  }
}

// �ݹ��������
void InOrderRecursion(BinaryTreeNode* T){
  if(T != nullptr){
    InOrderRecursion(T->m_pLeft);
    std::cout<<T->m_nValue<<" ";
    InOrderRecursion(T->m_pRight);
  }
}

// �ݹ�������
void PostOrderRecursion(BinaryTreeNode* T){
  if(T != nullptr){
    PostOrderRecursion(T->m_pLeft);
    PostOrderRecursion(T->m_pRight);
    std::cout<<T->m_nValue<<" ";
  }
}

//�ǵݹ�ǰ�����
void PreOrderNonRecursion(BinaryTreeNode* T){
  if(T == nullptr){
    return;
  }
  // std::stack<BinaryTreeNode*> m_stack;
  // BinaryTreeNode* p = T;
  // while(!m_stack.empty() || p != nullptr){
  //   while(p != nullptr){
  //     m_stack.push(p);
  //     std::cout<<p->m_nValue<<" ";
  //     p = p->m_pLeft;
  //   }
  //   p = m_stack.top();
  //   m_stack.pop();
  //   p = p->m_pRight;
  // }
  std::stack<BinaryTreeNode*> m_stack;
  m_stack.push(T);
  BinaryTreeNode* p = nullptr;
  while(!m_stack.empty()){
    p = m_stack.top();
    std::cout<<p->m_nValue<<" ";
    m_stack.pop();
    if(p->m_pRight != nullptr){
      m_stack.push(p->m_pRight);
    }
    if(p->m_pLeft != nullptr){
      m_stack.push(p->m_pLeft);
    }
  }

  // std::stack<BinaryTreeNode*> m_stack;
  // m_stack.push(T);
  // BinaryTreeNode* p = nullptr;
  // while(p != nullptr || !m_stack.empty()){
  //   // printf("In while");
  //   p = m_stack.top(); // ��ֵһ�ݵ�ǰ˫�׽ڵ�
  //   std::cout<<p->m_nValue<<" ";
  //   m_stack.pop();
  //   if(p->m_pRight != nullptr){//
  //     m_stack.push(p->m_pRight);
  //   }
  //   if(p->m_pLeft != nullptr){//
  //     m_stack.push(p->m_pLeft);
  //   }
  // }
}

// �ǵݹ��������
void InOrderNonRecursion(BinaryTreeNode* T){
  if(T == nullptr){
    return;
  }
  BinaryTreeNode* p = T;
  std::stack<BinaryTreeNode*> m_stack;
  while(p != nullptr || !m_stack.empty()){
    while(p != nullptr){
      m_stack.push(p);
      p = p->m_pLeft;
    }
    if(!m_stack.empty()){
      p = m_stack.top();
      m_stack.pop();
      std::cout<<p->m_nValue<<" ";
      p = p->m_pRight;
    }
  }
}

// �ǵݹ�������
void PostOrderNonRecursion(BinaryTreeNode* T){
  if(T == nullptr){
    return;
  }
  BinaryTreeNode* p = T, *pre = nullptr;
  std::stack<BinaryTreeNode*> m_stack;
  while(p != nullptr || !m_stack.empty()){
    while(p != nullptr){
      m_stack.push(p);
      p = p->m_pLeft;
    }
    p = m_stack.top();
    //������Ϊ�ջ����ѷ��ʣ������ǰ�ڵ�
    if(p->m_pRight == nullptr || p->m_pRight == pre){
      std::cout<<p->m_nValue<<" ";
      pre = p;// ����ǰ�ڵ㸳ֵ��pre,�����ظ�����
      m_stack.pop();
      p = nullptr;
    }
    else{
      p = p->m_pRight;
    }
  }
}

// ��α���
void LevelOrder(BinaryTreeNode* T){
  BinaryTreeNode* p = T;
  std::queue<BinaryTreeNode*> queue;
  queue.push(p);
  while(!queue.empty()){
    p = queue.front();
    std::cout<<p->m_nValue<<" ";
    queue.pop();
    if(p->m_pLeft != nullptr){
      queue.push(p->m_pLeft);
    }
    if(p->m_pRight != nullptr){
      queue.push(p->m_pRight);
    }
  }
}


int main(){
  std::cout<<"Hello World!"<<std::endl;
  BinaryTreeNode* root = nullptr;
  const int length = 8;
  int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
  int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};
  /*
        1
     /     \
    2       3
   /       /  \
  4       5    6
   \          /
    7        8
  */
  try{
    root = Construct(preorder, inorder, length);
    // PrintTree(root);
    // DestroyTree(root);
  }
  catch(std::exception& exception){
    printf("Invalid Input. \n");
  }
  PreOrderRecursion(root);
  std::cout<<std::endl;
  InOrderRecursion(root);
  std::cout<<std::endl;
  PostOrderRecursion(root);
  std::cout<<std::endl;
  std::cout<<"~~~~~~~~~~~~~~~~~~"<<std::endl;
  PreOrderNonRecursion(root);
  std::cout<<std::endl;
  InOrderNonRecursion(root);
  std::cout<<std::endl;
  PostOrderNonRecursion(root);
  std::cout<<std::endl;
  printf("LevelTravel..\n");
  LevelOrder(root);
}


BinaryTreeNode* Construct(int* preorder, int* inorder, int length){
  if(preorder == nullptr || inorder == nullptr || length <= 0){
    return nullptr;
  }
  return ConstructCore(preorder, preorder + length -1, inorder, inorder + length -1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder,
                              int* startInorder, int* endInorder){
  // ǰ��������еĵ�һ�������Ǹ��ڵ��ֵ
  int rootValue = startPreorder[0];
  BinaryTreeNode* root = new BinaryTreeNode();
  root->m_nValue = rootValue;
  root->m_pLeft = root->m_pRight = nullptr;

  // ��ǰ�������һ������ֻ�������ڵ�
  if(startPreorder == endPreorder){
      if(startInorder == endInorder && *startPreorder == *startInorder)
          return root;
      else{
          std::logic_error ex("Invalid input.");
          throw std::exception(ex);
      }
  }

  // ������������ҵ����ڵ�(�����в��������ڵ�)
  int* rootInorder = startInorder;
  while(rootInorder <= endInorder && *rootInorder != rootValue)
    ++ rootInorder;

  if(rootInorder == endInorder && *rootInorder != rootValue){
    std::logic_error ex("Invalid input.");
    throw std::exception(ex);
  }

  int leftLength = rootInorder - startInorder;
  int* leftPreorderEnd = startPreorder + leftLength;
  if(leftLength > 0){
    // ����������
    root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd,
                                  startInorder, rootInorder - 1);
  }

  if(leftLength < endPreorder - startPreorder){
    // ����������
    root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder,
                                   rootInorder + 1, endInorder);
  }
  return root;
}


BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}

void PrintTreeNode(const BinaryTreeNode* pNode)
{
    if(pNode != nullptr)
    {
        printf("value of this node is: %d\n", pNode->m_nValue);

        if(pNode->m_pLeft != nullptr)
            printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
        else
            printf("left child is nullptr.\n");

        if(pNode->m_pRight != nullptr)
            printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
        else
            printf("right child is nullptr.\n");
    }
    else
    {
        printf("this node is nullptr.\n");
    }

    printf("\n");
}

void PrintTree(const BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != nullptr)
    {
        if(pRoot->m_pLeft != nullptr)
            PrintTree(pRoot->m_pLeft);

        if(pRoot->m_pRight != nullptr)
            PrintTree(pRoot->m_pRight);
    }
}

void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}
