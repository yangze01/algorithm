#include<stdio.h>
#include<tchar.h>
int GetSize(int data[]){
  return sizeof(data);
}

int _tmain(int argc, _TCHAR* argv[]){
  int data1[] = {1,2,3,4,5};
  int size1 = sizeof(data1);
  printf("the size of data1 is: %d", size1);
}
