#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
struct E{
  char name[101];
  int age;
  int score;
  bool operator < (const E &b) const{//����c++���������ֱ�Ӷ���С�������
  // �����ͨ����Ҫ�϶�Ĵ洢�ռ䣬�����ֵ���ݣ���Ȼ��ϴ����ġ�ջ���ռ䣬
  // Ҳ��Ҫ�϶��ʱ��ʵʩ���ƹ��̡���Ϊconst���� const��Ա���������޸Ĳ���������
  // const���� ���������޸�
  // const��Ա�����У������޸��κ����Ա����
  // const��Ա�������ܵ��÷�const��Ա��������Ϊ��const��Ա�������Ի��޸ĳ�Ա����
  }
}
// using namespace std;
int main(){
  std::cout<<"hello world!"<<std::endl;
}
