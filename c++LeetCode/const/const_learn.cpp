#include<iostream>
using namespace std;

void testModifyConst(const int _x){
  // 2. const���κ�������
  // _x = 5; // ���ݹ����Ĳ������ɸı�
  cout<<_x<<endl;
}

class Point{
  //3. const���γ�Ա����
public:
  Point(int _x):x(_x){}

  void testConstFunction(int _x) const{
    cout<<"in the const member function"<<endl;
    cout<<"the x and _x is "<<x<<" "<<_x<<endl;
    //������const��Ա�����У������޸��κ����Ա����
    // x = _x;

    //����const��Ա�������ܵ��÷�const��Ա��������Ϊ��const��Ա�������ܻ��޸ĳ�Ա����
    // modify_x(_x);
  }

  void modify_x(int _x){
    x = _x;
    // return x;
  }

  int x;
};

//4. const ���κ�������ֵ
//(1) ָ�봫��
const int * mallocA(){//const data, non-const pointer
// �������const data, non-const pointer, ����ֵҲ���븳��const data,
// non-const pointer. ��Ϊָ��ָ��������ǳ��������޸�
  int *a = new int(2);
  return a;
}
//(2) ֵ����
// �����������ֵ���á�ֵ���ݷ�ʽ����
// ���ں�����ѷ���ֵ���Ƶ��ⲿ��ʱ�Ĵ洢��Ԫ�У���const����û���κμ�ֵ��
// ��Ҫ�Ѻ���int GetInt(void) Я��const int GetInt(void)
// ��Ҫ�Ѻ���A GetA(void) д�� const A GetA(void)������AΪ�û��Զ������������

int main(){
  // 1. const ���γ�Ա����
  int a1 = 3;
  const int a2 = a1;

  int * a3 = &a1; // non-const data, non-const pointer
  const int * a4 = &a1; // const data, non-const pointer
  int * const a5 = &a1; // non-const data, const pointer
  int const * const a6 = &a1; // const data, const pointer
  const int * const a7 = &a1; // const data, const pointer
  // *a4 = 6;
  *a5 = 6;
  // *a6 = 5;
  cout<<*a3<<" "<<*a4<<" "<<*a5<<" "<<*a6<<endl;

  // 2. const ���κ�������
  testModifyConst(5);

  // 3. const���γ�Ա����
  Point a(5);
  // *a = new Point(5);
  a.testConstFunction(8);
  a.modify_x(3);
  cout<<a.x<<endl;

  //4. const���κ�������ֵ
  const int *a = mallocA();
  // int *b = mallocA();

  return 0;
}
