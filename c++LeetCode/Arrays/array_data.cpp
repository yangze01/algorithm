#include<stdio.h>
#include<tchar.h>
int GetSize(int data[]){
  return sizeof(data);
}

int _tmain(int argc, _TCHAR* argv[]){
  // ���������5��������ÿ������ռ4���ֽڣ���˹�ռ��20�ֽ�
  // data2����Ϊָ�룬������ָ��������data1�ĵ�һ�����֣������ı�����Ȼ��һ��ָ��
  int data1[] = {1, 2, 3, 4, 5};
  int size1 = sizeof(data1);

  // data2����Ϊָ�룬����ָ������data1�ĵ�һ�����֣��������ı�����Ȼ��һ��ָ�룬��32λ
  // ϵͳ�ϣ�������ָ����sizeof���õ��Ľ������4��
  int* data2 = data1;
  int size2 = sizeof(data2);
  // ��������Ϊ�����Ĳ������д���ʱ�����ݾ��Զ��˻�Ϊͬ���͵�ָ�롣��˾���GetSize�Ĳ���
  // ����data������Ϊ���飬�������˻�Ϊָ�룬size3�Ľ����ȻΪ4��
  int size3 = GetSize(data1);
  printf("%d, %d, %d", size1, size2, size3);
}
