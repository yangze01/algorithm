#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
struct E{
  char name[101];
  int age;
  int score;
  bool operator < (const E &b) const{//利用c++运算符重载直接定义小于运算符
  // 类对象通常需要较多的存储空间，如果按值传递，必然会较大消耗“栈”空间，
  // 也需要较多的时间实施复制过程。因为const参数 const成员函数不会修改参数的内容
  // const参数 参数不可修改
  // const成员函数中，不能修改任何类成员变量
  // const成员函数不能调用非const成员函数，因为非const成员函数可以会修改成员变量
  }
}
// using namespace std;
int main(){
  std::cout<<"hello world!"<<std::endl;
}
