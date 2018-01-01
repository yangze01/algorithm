#include<stdio.h>
#include<tchar.h>
int GetSize(int data[]){
  return sizeof(data);
}

int _tmain(int argc, _TCHAR* argv[]){
  // 该数组包含5个整数，每个整数占4个字节，因此共占用20字节
  // data2声明为指针，尽管它指向了数组data1的第一个数字，但它的本质仍然是一个指针
  int data1[] = {1, 2, 3, 4, 5};
  int size1 = sizeof(data1);

  // data2声明为指针，尽管指向数组data1的第一个数字，但是它的本质仍然是一个指针，在32位
  // 系统上，对任意指针求sizeof，得到的结果都是4。
  int* data2 = data1;
  int size2 = sizeof(data2);
  // 当数组作为函数的参数进行传递时，数据就自动退化为同类型的指针。因此尽管GetSize的参数
  // 参数data被声明为数组，但它会退化为指针，size3的结果仍然为4。
  int size3 = GetSize(data1);
  printf("%d, %d, %d", size1, size2, size3);
}
